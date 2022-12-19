### 解题思路
1.这个题是个排序题，只不过最后要的是索引；
2.我们可以创造个数组，来存放士兵的个数，我们还需要这个数组中能够包含其索引信息（但不影响排序结果），那么事情便简单了，我们让数组中的士兵个数乘上索引的最大值+1，如数组[0,1,2,3,4,5,6,7,8,9] ->变成[10,11,12,13,14,15,16,17,18,19] 在排序最后我们在取他们对于（索引最大值+1）的余数即可

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count_number(int *arr,int arrSize){
    int count=0;
    for (int i=0;i<arrSize;i++){
        if (arr[i]==1)
            count++;
        else
            break;
    }
    return count;
}
int comp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int *soldiers;
    *returnSize = k;
    soldiers = (int*)malloc(sizeof(int)*matSize);
    for (int i=0;i<matSize;i++){
        soldiers[i] = count_number(mat[i],matColSize[i])*matSize + i;
    }
    qsort(soldiers,matSize,sizeof(int),comp);
    for (int i=0;i<matSize;i++){
        soldiers[i] = soldiers[i]%matSize;
    }
    return soldiers;
}
```