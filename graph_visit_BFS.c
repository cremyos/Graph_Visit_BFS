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
	
void BFS(ALGraph *G)
{
	int i=0;
	ArcNode *arc;
	Queue_Ptr p;
	int u=0;

	p=InitQueue(p);
	arc = (ArcNode *)malloc(sizeof(ArcNode));
	for(i=0;i<G->vexnum;i++)
	{
		if(!visit[i])
		{
			p=EnQueue(p,i);
			while(!EmptyQueue(p));
			{
				u=DeQueue(p,u);
				visit[u]=1;
				printf("%c -> ",G->vertices[u].data);
				for(arc=G->vertices[u].firstarc;arc;arc=arc->nextarc)
				{
					if(!visit[arc->adjvex-'A'])
					{
						p=EnQueue(p,arc->adjvex-'A');
					}
				}
			}
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
	
	BFS(G);


	
	return 0;
}
