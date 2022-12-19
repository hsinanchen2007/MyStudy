### 解题思路
题目稍微有些绕，本质就是进制的转换。但是这里我们需要对进制的转换进行稍加分析对比，我们一起来做这个探索的过程。

举个例子，十进制转2进制
本质就是满2进1，也就是说这这里是不存在2的，数的范围是从0-1，比如说10转换就是1010，每次都是取10的余数。除2进行循环
这里给一下2进制的转换过程
while(n>0)
{
    remainder=m%=2;//得到余数
    n/=2;//得到除数
}

紧接着，我们再来看这道题，这道题并不是普通的26进制的转换，这里满26并不会进1，并且最大的余数是可以取到26的，这里就容易被误导成27进制了，因为余数一般只能取到(进制数-1)。咱们只需要细心的观察就可以发现`商还是26的约数，除数还是26，只是我们的余数最大其实是取到26，并且这里商和余数都不能取0。`

所以我们只需要特别对26进行分析就可以了，如果一个数是26的倍数，我们的余数会是26，剩下的就是除26之后的商。

### 代码

```c
#define MaxSize 11
void reverse(char *result,int length)
{
    int i;
    char temp;
    for(i=0;i<length/2;i++)
    {
        temp=result[i];
        result[i]=result[length-i-1];
        result[length-i-1]=temp;
    }
}
char * convertToTitle(int n){
    int base=26;
    int remainder;
    int length=11;
    char *result=(char *)malloc(sizeof(char)*(length));

    length=0;
    while(n>26)
    {
        remainder=n%(base);
        if(remainder==0)//26的倍数
        {
            remainder=26;
            n--;
        }
        result[length++]=remainder+'A'-1;
        n/=base;
    }
    result[length++]=n+'A'-1;
    result[length]='\0';
    reverse(result,length);
    return result;
}
```