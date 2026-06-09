### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
**解法一：先求各个数得平方，最后排序**
 int cmp(int *a,int *b)
 {
     return *a - *b;
 }
int* sortedSquares(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    for(i = 0;i < ASize;i++)
    {
        res[i] = A[i]*A[i];
    }
    qsort(res,*(returnSize),sizeof(int),cmp);
    return res;
}


**解法二：双指针，正向读取整数，反向读取负数**
int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int left = 0;
    while (left < ASize && A[left] < 0)     //指针 right 反向读取负数部分，指针 left 正向读取非负数部分。
        left++;
    int right = left-1;
    *returnSize = ASize;
    int i = 0;
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    while(left < ASize && right >= 0)
    {
        if(A[left]*A[left] >= A[right]*A[right])                    
        {
            res[i++] = A[right]*A[right];
            right--;
        }
        else
        {
            res[i++] = A[left]*A[left];
            left++;
        }
    }
    while(right >= 0)
    {
        res[i++] = A[right]*A[right];
        right--; 
    }
    while(left < ASize)
    {
        res[i++] = A[left]*A[left];
        left++;
    }
    return res;
}
```