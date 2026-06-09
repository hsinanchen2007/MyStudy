解题思路 也是用了额外的空间，不过看题解好多人开了两个数组再合并感觉有点麻烦了，只开一个数组，一个从0开始加入偶数，一个开始从ASize - 1存入奇数，双指针一趟遍历就可以了。
```
代码块
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * ASize);
    memset(res, 0, sizeof(int) * ASize);
    int i, j = 0, k = ASize - 1;
    for(i = 0;i < ASize;i++)
    {
        if(A[i] % 2 == 0)
        {
            res[j++] = A[i];
        }
        else
        {
            res[k--] = A[i];
        }
    }
    *returnSize = ASize;
    return res;
}
