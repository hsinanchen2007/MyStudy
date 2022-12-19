### 解题思路
借助UThash,不过执行用时感人

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct HASH{
    int data;
    int index;
    UT_hash_handle hh;
};
int cmp(const void *x,const void *y){
    return *(int*)x-*(int*)y;
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    struct HASH *hashmap=NULL;
    struct HASH *s;
    int i,j;
    int *res=(int*)malloc(sizeof(int)*arrSize);
    for(i=0;i<arrSize;i++)res[i]=arr[i];        //临时数组
    qsort(arr,arrSize,sizeof(int),cmp);
    for(i=0,j=i+1;i<arrSize;i++){
        HASH_FIND_INT(hashmap,&arr[i],s);
        if(s==NULL){
            s=(struct HASH*)malloc(sizeof(struct HASH));
            s->data=arr[i];
            s->index=j++;
            HASH_ADD_INT(hashmap,data,s);
        }
        //else continue;        若存在重复元素,j不自加
    }
    for(i=0;i<arrSize;i++){
        HASH_FIND_INT(hashmap,&res[i],s);
        res[i]=s->index;
    }
    *returnSize=arrSize;
    return res;
}
```