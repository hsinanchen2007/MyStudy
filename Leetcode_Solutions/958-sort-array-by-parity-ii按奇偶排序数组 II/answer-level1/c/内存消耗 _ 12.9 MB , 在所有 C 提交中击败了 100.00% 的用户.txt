### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(void * a, void *b){
    return *(int *)a > *(int *)b;
}

void swap(int * a, int * b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    //1. 快速排序 额外分配空间操作

    //2. 不需要额外内存 双指针
    if(ASize == 0){
        *returnSize = 0;
        return NULL;
    }

    //qsort(A, ASize, sizeof(int), cmp);
    int i = 0;
    int j = 1;

    while(i < ASize - 1){
        if(A[i] % 2 == 1){
            while(j < ASize && A[j] % 2 == 1){
                j += 2;
            }
            swap(A + i, A + j);
        }
        i += 2;
    }

    * returnSize = ASize;
    return A;
}
```