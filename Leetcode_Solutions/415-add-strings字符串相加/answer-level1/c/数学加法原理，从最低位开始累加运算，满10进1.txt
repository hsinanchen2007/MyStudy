![image.png](https://pic.leetcode-cn.com/3b522ffaa9abef2d7e937d9522b391c76ed086c0f4f72a317f77653b2d716b82-image.png)
### 解题思路
1. 申请个存结果的空间，空间大小要比参数中的两个字符串中最长的strlen还要长2位，一位用于结尾存结束符\0，另一个用于最高位预留的进位。
2. 下标`unit1-i``unit2-i` `unit-i`分别表示两个入参和结果的位下标，起始i=0即代表各自的个位数；
3. `carrybit`用于标记当前位累加超过10时需要进位1，当前位累加也应考虑这位，用完记得清零；
4. 预留的`ret[0]`要不要用，只需要考虑上一次计算是否有进位。
5. 返回字串之前记得检查预留的一位是否使用，没使用需要将字符串指针跳过这个空的字符。

### 代码

```c
char * addStrings(char * num1, char * num2){
    int len1=strlen(num1);
    int len2=strlen(num2);
    int unit1=len1-1;//个位数下标
    int unit2=len2-1;
    int cnt=(len1>=len2)?len2:len1;//位数少的那个数决定需要进行多少次累加
    int leftcnt=(len1>=len2)?len1-len2:len2-len1;
    int len=(len1>=len2)?len1+2:len2+2;//存结果的长度，多出两位：一个存可能出现的最高位进位，一个存结束符'\0'
    char *ret=(char*)malloc((len)*sizeof(char));
    int unit=len-2;//len-1下标给了'\0'
    ret[0]=0;
    ret[len-1]='\0';
    int carrybit=0;
    int i=0;
    for(;i<cnt;i++)
    {
        ret[unit-i]=(num1[unit1-i]-'0'+num2[unit2-i]-'0'+carrybit)%10+'0';
        if((num1[unit1-i]-'0'+num2[unit2-i]-'0'+carrybit)>=10)
        {
            carrybit=1;
            continue;
        }
        carrybit=0;//使用完进位，清零
    }
    //接下来处理两个相加数中，较多位数的多出来的高位
    //printf("unit-i: %d\n",unit-i);
    //printf("i:%d\n",i);
    //printf("cnt: %d\n",cnt);
    //printf("leftcnt: %d\n",leftcnt);
    for(;i<cnt+leftcnt+1;i++)//多一位，为新增的保留的最高位进位
    {
        if(i!=cnt+leftcnt)//还有剩余的高位未填
        {
            ret[unit-i]=(len1>=len2)?(num1[unit1-i]-'0'+carrybit)%10+'0':(num2[unit2-i]-'0'+carrybit)%10+'0';
            int temp=(len1>=len2)?(num1[unit1-i]-'0'+carrybit):(num2[unit2-i]-'0'+carrybit);
            if(temp>=10)
            {
                carrybit=1;
                continue;
            }
            carrybit=0;//使用完进位，清零
        }
        else if(carrybit==1)
            ret[unit-i]=carrybit+'0';
    }

    while(*ret==0)//忽略掉开头的空字符
        ret++;
return ret;
}
```