### 解题思路
思路就是略过空格、存储正负号、获取数字。

需要注意的地方在代码注释中。

【一个技巧】：判断long型变量result有无存储超过int范围的数的方法：
```c
(int)result != result;  // 如果作int强制类型转化后不等于自己，则存储的数超过了int范围
```

【一个易错点】（这个易错点使用上述技巧则能避免，但很常见，所以写在这）：
```c
int MAX = INT_MAX;     // MAX的值为int型能存储的最大值
int result = 1;     // 让result为一个非常小的数
int flag = (result > MAX + 1) ? 1 : 0;
```
以上程序的`flag`为1，即`result>MAX+1`，这绝对不是我想要的结果。
仔细分析原因发现：MAX和1都是`int`型，两者相加得到的值若强行装入`int`，会造成溢出，经过测试，这个值为一个很小的负数，则result大于它就不奇怪了。改正方法是在`MAX`前加`(long)`。

### 代码

```c
#include<string.h>

///////////////////////////////////////////
// 以下方法不太好，因为获取的数字序列不管有没有超过范围，都要算出它，这就可能造成溢出（StringtoInt中可能long型也无法存储计算结果）
//
// long exponent(int count){
//     int result = 1;
//     for(int i=1;i<=count;i++){
//         result *= 10;
//     }
//     return result;
// }

// int StringtoInt(char * result, int flag){
//     int length = strlen(result);
//     long s = 0, temp = 0;
//     for(int i=0;i<length;i++){
//         temp = (result[i] + 0 - '0') * exponent(length-1-i);
//         s += temp;
//     }

//     s *= flag;

//     if(s>2147483647)return 2147483647;
//     else if(s<-2147483648)return -2147483648;
//     else return (int)s;
// }
////////////////////////////////////////

int myAtoi(char * str){
    // int flag = 1;
    short flag = 1;
    // char * result = (char *)malloc(sizeof(char) * 12);
    int i=0;
    const int MAX = 2147483647;
    const int MIN = -2147483648;
    long result = 0;

    if(*str=='\0')return 0;

    while(*str==' ')str++;    // 略过空格部分
    if((*str<'0'||*str>'9')&&*str!='+'&&*str!='-')return 0;

    if(*str=='+'){  // 存储开头的正负号
        str++;
    }
    else if(*str=='-'){
        str++;
        flag = -1;
    }

    if(*str<'0'||*str>'9')return 0; // 处理数字部分
    else{
        // while(*str>='0'&&*str<='9'){
        while((*str>='0')&&(*str<='9')){
            // result[i++] = *str;
            result = result * 10 + (*str - '0');

            // 实时监控当前数有无超出限制
            if(flag==1&&result>MAX){
                result = MAX;
                break;
            }
            else if(flag==-1&&result>(long)MAX+1){  // 易错点，如果不加long类型转换，由于MAX和1都是int型，则相加的中间结果会溢出（刚好比int的最大值大1，这个值强行存入int会变成一个很小的负数），此时即使result很小也比它大
                result = MAX + 1;
                break;
            }
            // 另一个更简单的实时监控当前数有无超出限制的方法：(int)result!=result，自己进行int强制类型转换后和自己不相等。

            str++;
        }
        // result[i] = '\0';
    }

    // return StringtoInt(result, flag);

    result = result * flag;
    return (int)result;

}
```