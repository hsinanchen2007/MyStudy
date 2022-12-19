```
void SubFuncBFS(int n, int** graph, int index, int *visited)
{
    int i;
	visited[index] = 1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && graph[index][i] == 1) {
			SubFuncBFS(n, graph, i, visited);
		}
	}
}

int countComponents(int n, int** edges, int edgesSize, int* edgesColSize)
{
    int i;
    int returnValue = 0;
    int *visited = (int *)malloc(n * sizeof(int));
    memset(visited, 0, n * sizeof(int));
    int **graph;

    graph = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        memset(graph[i], 0, n * sizeof(int));
    }

    for (i = 0; i < edgesSize; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            SubFuncBFS(n, graph, i, visited);
            returnValue++;
        }
    }
	
    return returnValue;
}
```
