### 解题思路
时间复杂度O(n)
该题目要求在最末尾的数字上加一，那么可能会涉及进位，如129---130，999---1000，因此可以考虑从数组末端往前循环，如果遇到小于9的数字，则加一结束，否则进位。如果循环结束后程序任没有终止，则代表是999之类的数字，此时应当申请比原来数组长度大一的数组，将其变为100之类的数字。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]<9)
        {
            
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    int* result=(int*)malloc(sizeof(int)*(digitsSize+1));
    result[0]=1;
    for(int i=1;i<(digitsSize+1);i++)
    {
        result[i]=0;
    }
    *returnSize=digitsSize+1;
    return result;
}


```