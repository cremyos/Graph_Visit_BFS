CC = gcc 
OUT = graph_visit_BFS
OUT2 = queue
all:Adj_list.h Queue.h
	$(CC) -o $(OUT) $(OUT).c $(OUT2).c -I . -Wall
debug:
	$(CC) -g $(OUT).c $(OUT2).c -o $(OUT) -I . -Wall
clean:
	rm $(OUT)

