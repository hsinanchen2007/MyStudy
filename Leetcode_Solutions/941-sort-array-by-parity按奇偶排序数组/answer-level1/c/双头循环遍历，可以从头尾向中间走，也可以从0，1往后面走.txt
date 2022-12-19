### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int start = 0;
    int end = ASize - 1;
    *returnSize = ASize;
    while(start < end)
    {
        if(A[start]%2 != 0)    //当 头是奇数
        {
            if(A[end] %2 == 0)   //尾是偶数，把二者互换
            {
                int tmp = A[start];
                A[start++] = A[end];
                A[end--] = tmp;
            }
            else                   //尾是奇数，则--尾
                --end;
        }
        else                        //头是偶数，则++头
            ++start;
    }
    return A;

}
```