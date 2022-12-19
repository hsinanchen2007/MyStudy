### 解题思路
先用strlen()求出len作为数组长度

先使用一次while(i<len)的循环 找到第一个不为空格的字符，

进入下一步判断，如果是'+''-'或者是数字，都进行对应的负号正号的操作；如果是其他就说明不成立直接return 0即可。

再次进入while(i<len)的循环找出接下来连续的数字大小，并不断的判断是否溢出（关于如何判断整形溢出的代码详解在之前 7.整数反转 中有），再根据之前的符号来进行对应数字的操作。
其中有一点**十分关键**，re = re*10+(str[i]-'0')的****括号十分重要****。因为如果没有括号，最后一步时，你的re == MIN/10(边界),你的re*10之后会先加上str[i],从而造成溢出（我错了好几遍才意识到）。

### 代码

```c

int myAtoi(char * str){
    int len = strlen(str);
    int MAX = 2147483647,MIN = -2147483648;
    int i = 0,re = 0;
    int flag = 1;
    while(i<len){
        if(str[i] == ' ')
            i++;
        else 
            break;
    }
    if(str[i]=='-'){
        flag = -1;
        i++;
        }
    else if(str[i] == '+')
        i++;
    else if(str[i]<='9'&&str[i]>='0');
    else return re;
    while(i<len){
        if(str[i]>'9'||str[i]<'0') break;
        if(re>MAX/10||(re==MAX/10&&(str[i]-'0')>=7)) return MAX;
        if(re<MIN/10||(re==MIN/10&&(str[i]-'0')>=8)) return MIN;
        if(flag == 1)
            re = re*10+(str[i]-'0');
        else
            re = re*10-(str[i]-'0');
        i++;
    }
    return re;
}
```