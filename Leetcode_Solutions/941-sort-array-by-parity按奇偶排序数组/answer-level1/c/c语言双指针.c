### 解题思路
遍历数组，遇到偶数放到前面，遇到奇数放到后面。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int* num=(int*)malloc(sizeof(int)*ASize);
    int left=0;
    int right=ASize-1;
    for(int i=0;i<ASize;i++)
    {
        if(A[i]%2==0)
        {
            num[left]=A[i];
            left++;
        }
        else
        {
            num[right]=A[i];
            right--;
        }
    }
    *returnSize=ASize;
    return num;
}
```