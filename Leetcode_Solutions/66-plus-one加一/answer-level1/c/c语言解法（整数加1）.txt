### 解题思路
从后往前遍历，如果遇到不是9的数直接加1返回原数组，否则一直赋值为0，如果第一个循环结束则表明全部为0，则申请一个加1的数组然后首位为1，其余为0，返回。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]!=9)
        {
                digits[i]++;
                *returnSize=digitsSize;
                return digits;
        }
        digits[i]=0;
    }
    int* num=(int*)calloc(sizeof(int),(digitsSize+1));
    num[0]=1;
    *returnSize=digitsSize+1;
    return num;
}
```