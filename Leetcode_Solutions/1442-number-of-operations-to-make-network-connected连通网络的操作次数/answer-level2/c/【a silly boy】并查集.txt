```
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int Find(int *graph, int a) {
    while(graph[a] != -1) {
        a = graph[a];
    }
    return a;
}

void Union(int *graph, int a, int b) {
    int tmpA = Find(graph, a);
    int tmpB = Find(graph, b);

    if (tmpB != tmpA) {
        graph[tmpB] = tmpA;
    }

    return;
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    if ((n == 0) || (connections == NULL) || (connectionsSize == 0) || (connectionsColSize == NULL) || (*connectionsColSize == 0)) {
        return 0;
    }

    if (connectionsSize == 1) {
        if (n > 2) {
            return -1;
        }
        if (n == 2) {
            return 0;
        }
    }
    
    int i;
    int *graph = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        graph[i] = -1;
    }

    int count = 0;
    int needConneted = 0;
    int tmpA;
    int tmpB;

    for (i = 0; i < connectionsSize; i++) {

        tmpA = Find(graph, connections[i][0]);
        tmpB = Find(graph, connections[i][1]);

        if (tmpA == tmpB) {
            //多余的线缆
            count++;
        } else {
            Union(graph, connections[i][0], connections[i][1]);
        }
    }
    //printf("count: %u\n", count);

    for (i = 0; i < n; i++) {
        if (graph[i] == -1) {
            needConneted++;
        }
    }
    needConneted--;

    //printf("count: %u, needConneted: %u\n", count, needConneted);
    if (count >= needConneted) {
        return needConneted;
    } else {
        return -1;
    }
}
```
