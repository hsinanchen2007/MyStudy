### 解题思路
额 直接看代码吧

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* ret=(int*)malloc(sizeof(int)*(digitsSize+1));
    int carry=1;//进位标志
    for(int i=digitsSize-1; i>=0; i--)
    {
        if(digits[i]+carry<10)
        {
            digits[i]=digits[i]+1;
            carry=0;
            break;
        }
        digits[i]=0;
        carry=1;
    }
    if(carry==1)
    {
        for(int i=digitsSize; i>=1; i--)
            ret[i]=digits[i-1];
        ret[0]=1;
        *returnSize=digitsSize+1;
    }
    else
    {
        for(int i=digitsSize-1; i>=0; i--)
        ret[i]=digits[i];
        *returnSize=digitsSize;
    }
    
    return ret;
}
```