### 解题思路
此处撰写解题思路
申请ASizeA个int数组，取出每个元素，奇数从结尾放，偶数从头放
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *ret = malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    int head = 0,tail = ASize -1;

    for(int i = 0; i < ASize;i++){
        if(A[i] & 1){
            ret[tail--] = A[i];
        }else{
            ret[head++] = A[i];
        }
    }

    return ret;
}
```