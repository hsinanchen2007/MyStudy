/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

	/**
	 * 创建图的邻接表: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
	 * [
	 * 		0: {1},	
	 * 		1: {0, 2, 3},
	 * 		2: {1},
	 * 		3: {1}
	 * ] 
    */


int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){

    int *ret = NULL;

    if (edges == NULL) {
        return NULL;
    }

    if (n == 1) {
        *returnSize = 1;
        ret = malloc(sizeof(int) * 1);
        ret[0] = 0;
        return ret;
    }

    int i;
    int head = 0;
    int tail = 0;
    int lenCnt = n;
    int last = 0;
    int node;
    int nodeSize;
    int **graph = (int **)malloc(sizeof(int *) * n);
    int *degree = (int *)malloc(sizeof(int) * n);
    int *queue = (int *)malloc(sizeof(int) * n);
    int *colSize = (int *)malloc(sizeof(int) * n);

    memset(degree, 0, sizeof(int) * n);
    memset(colSize, 0, sizeof(int) * n);

    for (i = 0; i < n; i++) {
        graph[i] = malloc(sizeof(int));
        memset(graph[i], 0, sizeof(int));
    }

    for (i = 0; i < edgesSize; i++) {
        graph[edges[i][0]][degree[edges[i][0]]] = edges[i][1];
        graph[edges[i][1]][degree[edges[i][1]]] = edges[i][0];
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        graph[edges[i][0]] = realloc(graph[edges[i][0]], sizeof(int) * (degree[edges[i][0]] + 1));
        graph[edges[i][1]] = realloc(graph[edges[i][1]], sizeof(int) * (degree[edges[i][1]] + 1));
    }

    for (i = 0; i < n; i++) {
        colSize[i] = degree[i];
        if (degree[i] == 1) {
            queue[tail] = i;
            tail++;
        }
    }

    while (lenCnt > 2) {
        last = tail;
        lenCnt -= (tail - head);

        while(head < last) {
            node = queue[head];
            nodeSize = colSize[node];

            for (i = 0; i < nodeSize; i++) {
                if (degree[graph[node][i]] > 0) {
                    degree[graph[node][i]]--;
                }
                if (degree[graph[node][i]] == 1) {
                    queue[tail] = graph[node][i];
                    tail++;
                }
            }

            head++;
        }

    }

    ret = (int *)malloc(sizeof(int) * (tail - head));
    i = 0;
    while (head < tail) {
        ret[i] = queue[head];
        i++;
        head++;
    }

    *returnSize = i;
    return ret;
}


