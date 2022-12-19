### 解题思路

![image.png](https://pic.leetcode-cn.com/4f8e49c9f49010a865b35570e98c0198da9a0bf8f1fb8f2cc7f161cc5c5c39de-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int *)a>*(int *)b?1:-1;
}
int* sortedSquares(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    
    int mid=0;
    while(mid<ASize && A[mid]<0) mid++;//小心数组溢出
    for(int i=0;i<ASize;i++){
        A[i] = pow(A[i],2);
    }
    // qsort(A,ASize,sizeof(int),cmp);
    if(mid==0 || ASize==1) return A;

    int *tmp = (int *)calloc(ASize,sizeof(int));
    //两个有序数组合并为一
    int left=mid-1,index=0;
    while(left>=0 && mid<ASize){
        if(A[left]<=A[mid]){
            tmp[index++] = A[left--];
        }else
            tmp[index++] = A[mid++];

    }
    while(left>=0)   tmp[index++] = A[left--];
    while(mid<ASize) tmp[index++] = A[mid++];

    return tmp;
}
```