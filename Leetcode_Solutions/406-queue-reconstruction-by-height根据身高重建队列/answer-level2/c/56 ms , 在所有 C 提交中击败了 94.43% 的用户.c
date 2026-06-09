

使用qsort对数据进行排序```
代码块

int cmp(const void* a, const void *b){
   if (**(int**)a != **(int**)b){
       return  **(int**)b - **(int**)a;
   }
   return  *(((int*)*(int**)a)+1) - *(((int*)*(int**)b)+1);
}



int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (peopleSize == 0){
        * returnSize = 0;
        return 0;
    }
    int *tmpNode = 0;

    qsort(people, peopleSize, sizeof(int*), cmp); //使用qsort对数组进行排序！！！！！
#if 0
  
    for(int i = 0; i < peopleSize; i++){
        for(int j = i + 1; j < peopleSize; j++){
            if(people[i][0] < people[j][0]){
                tmpNode = people[i];
                people[i] = people[j];
                people[j] = tmpNode;
            }
            if (people[i][0] == people[j][0]){
                if(people[i][1] > people[j][1]){
                    tmpNode = people[i];
                    people[i] = people[j];
                    people[j] = tmpNode;
                }
            }
        }
    }
#endif
    int** result = (int**) malloc(sizeof(int*) * peopleSize);
    int tmpReturnSize = 0;
    int* tmpReturnColumnSizes = (int*) malloc(sizeof(int) * peopleSize);
    int* curNode = 0;
    curNode = (int*)malloc(sizeof(int) * peopleColSize[0]);

    for(int i = 0; i< peopleSize; i++){
        curNode = (int*)malloc(sizeof(int) * peopleColSize[0]);
        curNode[0] = people[i][0];
        curNode[1] = people[i][1];
        for(int j = tmpReturnSize - 1; j >= people[i][1]; j--){
            result[j+1] = result[j];
        }
        result[people[i][1]] = curNode;
        tmpReturnColumnSizes[tmpReturnSize] = 2;
        tmpReturnSize++;
    }
    *returnSize = tmpReturnSize;
    * returnColumnSizes = tmpReturnColumnSizes;
    return result;
}
