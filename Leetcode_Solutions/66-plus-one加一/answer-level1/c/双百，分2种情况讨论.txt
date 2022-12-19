### 解题思路
直接用数组处理，若转化为数字处理，存在溢出的情况。
用数组处理，关键看returnSize是否增大（分两种情况，如9999、999和8549、8999两类）和连续的9的位数

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i,*p,x;
    x=digitsSize-1;
    if(digits[digitsSize-1]==9&&digits[0]==9){
        p=(int *)malloc(sizeof(int)*(digitsSize+1));
        p[0]=1;
        for(i=1;i<=digitsSize;i++){
            p[i]=0;
        }
        *returnSize=digitsSize+1;
        return p;
    } 
    else{
        p=(int *)malloc(sizeof(int)*(digitsSize));
        *returnSize=digitsSize;
        while(digits[x]==9){//从结尾开始找连续的9，直到不是9的地方停下
            x--;
        }
        *(p+x)=digits[x]+1;//连续的9前面一位加1
        for(i=0;i<x;i++){//其余不变
            p[i]=digits[i];
        }
        for(i=x+1;i<=digitsSize-1;i++){//对连续的9的地方置为0
            p[i]=0;
        }   
        return p;
    }


}
```