·基本思想与其他题解相同。
·改进：计算距离时不开方，保留为距离的平方，以免使用double型，减少计算步骤；
·代码如下：

```
int cmp(const void* a, const void* b){
    if(*(int*) a > *(int*)b){
        return 1;
    }else{
        return -1;
    }
}
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    int cmp(const void* a, const void* b);
    int* Distances = (int*)malloc(sizeof(int) * pointsSize);
    int Num_Boo = 0;
    for(int i = 0; i < pointsSize; i++){
        for(int j = 0; j < pointsSize; j++){
            Distances[j] = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
        }
        qsort(Distances, pointsSize, sizeof(int), cmp);
        int Count = 1;
        for(int j = 1; j < pointsSize; j++){
            if(Distances[j] == Distances[j - 1]){
                Count++;
            }else if(Count > 1){
                Num_Boo += Count * (Count - 1);
                Count = 1;
            }else{
                continue;
            }
        }
        Num_Boo += Count * (Count - 1);
    }
    free(Distances);
    return Num_Boo;
}
```