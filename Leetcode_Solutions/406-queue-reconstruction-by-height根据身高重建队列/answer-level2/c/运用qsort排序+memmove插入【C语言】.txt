
/**
1、先按身高从大到小排序，再根据每个人前面身高大于等于他的计算插人即可。
2、运用qsort 和 memmove 库函数即可。

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
int compar(const void *p1, const void *p2);
void *memmove(void *str1, const void *str2, size_t n)
**/

```
typedef struct peopleStr{
    int height;
    int hCount;
}peopleStr;

int heighCmp(const void * hCount1, const void * hCount2){
    const peopleStr * l1 = *(const peopleStr**)hCount1;
    const peopleStr * l2 = *(const peopleStr**)hCount2;
    if(l1->height == l2->height){
        return ((l1->hCount) - (l2->hCount));
    }
    return ((l2->height) - (l1->height));
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){

    int heightCount;
    int* colSize = NULL;
    colSize = (int*)malloc(sizeof(int)*peopleSize);
    
    int** res = NULL;
    res = (int**)malloc(sizeof(int*)*peopleSize);
    
    qsort(people, peopleSize, sizeof(int*), heighCmp);

    for(int i = 0; i<peopleSize; i++){
        heightCount  = people[i][1];        
        memmove(&res[heightCount+1], &res[heightCount], (i - heightCount)*sizeof(int*));
        res[heightCount] = (int*)malloc(sizeof(int)*2);
        res[heightCount][0] = people[i][0];
        res[heightCount][1] = people[i][1];
    }   
    *returnColumnSizes = peopleColSize;
    *returnSize = peopleSize;
    return res;
}
```
