/*
 ************************************************
 *Name : graph_visit_BFS.c                      *
 *Date : 2015-06-03                             *
 *Author : sniper                               *
 *Aim : The Adjacency list storage the graph and*
 *      visit it using the BFS.                 *
 ************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "Adj_list.h"
#include "Queue.h"

int visit[MAX_VERTEX_NUM]={0};

/* 
 *Create the Adjacency list
 */
ALGraph* create(ALGraph *G)
{
	int i,j;
	int node_pair1,node_pair2;
	ArcNode *arc;
	
	node_pair1=0;
	node_pair2=0;
	i=0;
	j=0;
	printf("please input the number of node and edge: ");
	scanf("%d %d",&G->vexnum,&G->arcnum);

	for(i=0;i<G->vexnum;i++)
	{
		G->vertices[i].data = 'A'+i;
		G->vertices[i].firstarc=NULL;
		/*
		 *prepare for visiting
		 */
		visit[i]=0; 
	}	
	printf("finish the Node!\n");

	for(j=0;j<G->arcnum;j++)
	{
		printf("please input the node pair: ");  
  
        scanf("%d %d",&node_pair1,&node_pair2);  
		node_pair1-=1;
		node_pair2-=1;
        /* 
         *Node pair get match with each other  
         *and storage into the adjacency list. 
         */  
		arc = (ArcNode *)malloc(sizeof(ArcNode));  
		arc->adjvex = node_pair2+'A';  
		arc->nextarc=G->vertices[node_pair1].firstarc;  
		G->vertices[node_pair1].firstarc=arc;        
	}
	printf("finish the Adjacency List\n");
	return G;
}

/*
 *BFS visit
 *We need a queue to help
 */
void BFSTraverse(ALGraph *G)
{
	int i;
	
	for(i=0;i<G->vexnum;i++)
		BFS(G,i);
}
	
void BFS(ALGraph *G,int i)
{
	int j=0,k=0;
	ArcNode *arc;
	Queue_Ptr p;
	int u=0;

	p=InitQueue(p);
	if(!visit[i])
	{
		printf("%c -> ",G->vertices[i].data);
		visit[i]=1;
	}
	p=EnQueue(p,i);
	while(EmptyQueue(p))
	{
		j=DeQueue(p,j);
		arc=G->vertices[j].firstarc;
		while(arc)
		{
			if(visit[arc->adjvex-'A']==0)
			{
				visit[arc->adjvex-'A']=1;
				printf("%c -> ",G->vertices[arc->adjvex-'A'].data);
				p=EnQueue(p,arc->adjvex-'A');
			}
			arc=arc->nextarc;
		}
	}
}


int main()
{
	ALGraph *G;
	int i;	
	
	i=0;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	G = create(G);

	printf("print the BFS\n");
	printf("****************************\n");
	
	BFSTraverse(G);
	
	printf("\n");


	
	return 0;
}
