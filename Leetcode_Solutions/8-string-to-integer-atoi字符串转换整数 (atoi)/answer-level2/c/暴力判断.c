### 解题思路
![1.jpg](https://pic.leetcode-cn.com/43ee4a6725919eeff55e61005d2e5acc13868c6667b8f89a069b742101600dbb-1.jpg)

题目并不难，理清思路就好，直接上注释。

### 代码

```c
int myAtoi(char * str){
    while (*str == 32)//跳过无用的空格
        ++str;
    int result = 0;
    if (*str == 43){//对+号的处理
        ++str;
        while (*str == 48)//跳过无用的0
            ++str;
        if (*str < 49 || *str > 57)//不构成数字，直接返回
            return 0;
        result = *str - 48;//*str - 48就是该字符的值
        ++str;
        while (*str > 47 && *str < 58){//遍历所有有效字符
            if (result > 214748364 || (result == 214748364 && (*str - 48) > 7))//防止越界
                return 2147483647;
            result = result * 10 - 48 + *str;//注意要先减后加，以防越界
            ++str;
        }
        return result;
    }else if (*str == 45){//对-号的处理
        ++str;
        while (*str == 48)//跳过无用的0
            ++str;
        if (*str < 49 || *str > 57)//不构成数字，直接返回
            return 0;
        result = 48 - *str;
        ++str;
        while (*str > 47 && *str < 58){
            if (result < -214748364 || (result == -214748364 && (*str - 48) > 8))
                return -2147483648;
            result = result * 10 + 48 - *str;//注意要先加后减，以防越界
            ++str;
        }
        return result;
    }else if (*str > 47 && *str < 58){//与对+号的处理类似
        while (*str == 48)
            ++str;
        if (*str < 49 || *str > 57)
            return 0;
        result = *str - 48;
        ++str;
        while (*str > 47 && *str < 58){
            if (result > 214748364 || (result == 214748364 && (*str - 48) > 7))
                return 2147483647;
            result = result * 10 - 48 + *str;
            ++str;
        }
        return result;
    }
    return result;
}
```