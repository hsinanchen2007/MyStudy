### 解题思路
先排除每一位全是9的情况，+1后会多一位，并且第一位1后面全0

然后设置进位为1，从末尾开始与进位相加（第一次正好相当于末尾+1）
加完后判断是否大于9，不大于的话将进位置于0，然后复制完原数组即可。

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    //只有全部是9 +1后才会多出一位。

    if(digitsSize==0)
    {
        int *s=(int*)malloc(sizeof(int));
        s[0]=1;
        *returnSize=1;
        return s;
    }

    int isAllNine = 1;//用于表示+1后是否多出一位
    for(int i=0;i<digitsSize;i++)
    {
        if(digits[i]!=9) {
            isAllNine=0 ;
            break;

        }
    }
    if(isAllNine==1) //10.....0 并多一位
    {
        int *result = (int*)malloc(sizeof(int)*(digitsSize+1));
        *returnSize =digitsSize+1;
        result[0]=1;
        for(int i=1;i<=digitsSize;i++)
        {
            result[i]=0;
        }

        return result;
    }

    //常规不多位。
    int add=1;//用于加法进位 

    *returnSize = digitsSize;
    int *result = (int*)malloc(sizeof(int)*(digitsSize));
    for(int i=digitsSize-1;i>=0;i--)
    {
        int t = digits[i]+add;
        if(t<10)
        {
            result[i] = t;
            add=0;
        }
        else
        {
            int p = t%10;
            result[i] =0;
            add=1;
        }
    }

    return result;



}


```