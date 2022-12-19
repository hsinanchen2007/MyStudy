### 解题思路
比较笨的办法，先选择A中的偶数放入结果数组中，再选择A中的奇数放入结果数组中。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
int i=0;
int* returnA=(int*)malloc(sizeof(int)*(ASize+1));
*returnSize=0;
for(i;i<ASize;i++){
    if(A[i]==0||A[i]%2==0){
        returnA[*returnSize]=A[i];
        (*returnSize)++;
    }
}
for(i=0;i<ASize;i++){
    if(A[i]%2==1){
        returnA[*returnSize]=A[i];
        (*returnSize)++;
    }
}
return returnA;
}
```