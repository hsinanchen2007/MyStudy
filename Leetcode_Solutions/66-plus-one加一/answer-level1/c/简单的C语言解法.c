对于某一位，有两种情况：
1. 情况1：该位不为9，不产生进位；
2. 情况2：该位为9，产生进位，且该位为0。
对于整个数组，有两种情况：
1. 情况3：不全为9，数组长度不会增加；
2. 情况4：全为9，则数组长度需要增加1位，且剩余位均位0。

代码思路：
从最后一位向前逐个计算，若该位符合情况1，则加1后程序结束；若符合情况2，则产生进位，继续向前一位计算；
从数组最后循环直到计算到数组第一个数字，若没有进位，则满足情况3，程序结束；若符合情况4，需要分配一个比原数组长1的空间，首位位1，其余位为0。

```
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i=digitsSize-1;
    int overflowFlag=1;
    while(i>=0){
        //情况1
        if(digits[i]<9){
            digits[i]++;
            overflowFlag=0;
            break;
        }
        //情况2
        else{
            digits[i]=0;
            i--;
        }
    }
    int* result=NULL;
    //情况4
    if(overflowFlag){
        *returnSize=digitsSize+1;
        result=(int*)malloc(sizeof(int)*(digitsSize+1));
        result[0]=1;
        for(int i=0;i<digitsSize;i++){
            result[i+1]=0;
        }
    }
    //情况3
    else{
        *returnSize=digitsSize;
        result=digits;
    }
    return result;
}
```
