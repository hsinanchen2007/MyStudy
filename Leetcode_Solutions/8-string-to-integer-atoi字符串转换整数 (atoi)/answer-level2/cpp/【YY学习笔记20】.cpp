### 解题思路
**1.前期判断：**  优先考虑若为空字符串则返回0。然后排除前面的非空字符，若此时已无字符，返回0；若此时字符非'+''-'，也非数字，返回0。
**2.核心：**  拼接数字。

————————————————————————————————————————————————

**2.1基本思路（正数）：**
```
while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
    result=result*10+(str[i]-'0');
    i++;
}
```
**2.2考虑到正负数问题：**
```
while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
    result=result*10+sign*(str[i]-'0');
    i++;
}
```
**2.3考虑到上下界问题：**
```
while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
    if(result>INT_MAX/10||(result==INT_MAX/10&&(str[i]-'0')>INT_MAX%10)) return INT_MAX;
    if(result<INT_MIN/10||(result==INT_MIN/10&&(str[i]-'0')>-(INT_MIN%10))) return INT_MIN;
    //小细节：负数%10为负数。
    
    result=result*10+sign*(str[i]-'0');
    i++;
}
```
### 知识点
**1.**  在脑海中又增加了一种新的测试用例'+-42'（同时出现两个符号）。
**2.**  负数取余还是负数。
**3.**  INT_MAX,INT_MIN由标准头文件<limits.h>定义。
**4.**  INT_MAX=2^31-1(2,147,483,647)
**5.**  INT_MIN=-2^31(-2,147,483,648)

### 感悟
日常崩溃。其实这道题的思路很简单，几分钟就能想出来，但是我不断完善，不断改bug的过程却持续了1个多小时，提交报错10多次。
以我现在的水平看来：码代码很多时候大方向上不会有问题，但是在某个细微的点上，一直不断的犯错。太磨人的性子了。
加油YY。
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i=0,sign=1,result=0;
        if(str==" ") return 0;
        //去除前面空格。
        for(i=0;i<str.length();++i){
            if(str[i]!=' ')
                break;
        }
        //如果第一个非空字符为：符号。
        if(str[i]=='-'){//错误点1：如果同时遇到例如(+-42)这种有两个符号的情况怎么处理。
            sign=-1;
            i++;
        }
        else if(str[i]=='+') i++;
        //如果第一个非空不为：非整数字符或仅包含空白字符。
        if(i==str.length()||str[i]<'0'||str[i]>'9')
            return 0;

        while(i<str.length()&&str[i]>='0'&&str[i]<='9'){//错误点2：错写成str[i]>'0'，脑子抽了。
            if(result>INT_MAX/10||(result==INT_MAX/10&&(str[i]-'0')>INT_MAX%10)) return INT_MAX;
            if(result<INT_MIN/10||(result==INT_MIN/10&&(str[i]-'0')>-(INT_MIN%10))) return INT_MIN;
            //错误点3：INT_MIN%10之后还为负数。
            result=result*10+sign*(str[i]-'0');//错误点4：最初没有考虑到sign问题，直接写成了result=result*10+(str[i]-'0')。
            i++;
        }
    return result;
    }
};
```