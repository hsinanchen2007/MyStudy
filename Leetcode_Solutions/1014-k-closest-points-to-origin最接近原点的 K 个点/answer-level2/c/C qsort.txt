```
typedef struct hash_node {
    int x;
    int y;
    int dis;
} Hash_Node;
int my_compare(const void* a, const void *b)
{
    Hash_Node *temp1 = (Hash_Node*)a;
    Hash_Node *temp2 = (Hash_Node*)b;
    return temp1->dis - temp2->dis;
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    Hash_Node *my_user = (Hash_Node*)malloc(sizeof(Hash_Node) * pointsSize);
    int i;
    for (i = 0; i < pointsSize; i++) {
        my_user[i].x = points[i][0];
        my_user[i].y = points[i][1];
        my_user[i].dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }

    qsort(my_user, pointsSize, sizeof(Hash_Node), my_compare);

    int **res = (int*)malloc(sizeof(int*) * K);
    *returnSize = K;
    *returnColumnSizes = (int*)malloc(sizeof(int) * K);
    i = 0;
    for (i = 0; i < K; i++) {
        (*returnColumnSizes)[i] = 2;
        res[i] = (int*)malloc(sizeof(int) * 2);
        res[i][0] = my_user[i].x;
        res[i][1] = my_user[i].y;
    }
    return res;
}
```
