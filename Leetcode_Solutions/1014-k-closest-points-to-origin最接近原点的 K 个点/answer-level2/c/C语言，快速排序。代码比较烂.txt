 int compare(const void *p1, const void *p2)
 {
     return *(int *)p1 - *(int *)p2;
 }

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    if (points == NULL || pointsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int distance[pointsSize];
    int **retArray;
    int arrIndex = 0;
    int i;

    retArray = (int **)malloc(sizeof(int *) * K);
    for (i = 0; i < K; i++) {
        retArray[i] = (int *)malloc(sizeof(int) * 2);
    }

    for (i = 0; i < pointsSize; i++) {
        distance[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    qsort(distance, pointsSize, sizeof(int), compare);

    while (arrIndex < K) {
        for (i = 0; i < pointsSize && arrIndex < K; i++) {
            if (distance[arrIndex] == points[i][0] * points[i][0] + points[i][1] * points[i][1]) {
                retArray[arrIndex][0] = points[i][0];
                retArray[arrIndex++][1] = points[i][1];
            }
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * K);
    for (i = 0; i < K; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = K;
    return retArray;
}