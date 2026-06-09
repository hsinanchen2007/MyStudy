### 解题思路
犯错记录
1. 字符的判断用了“”，而不是单引号‘’，导致除去空格失败
2. 没有判断过大过小值，读题不准确
3. 使用int值做return，导致在中途计算时溢出
4. 31位二进制误以为31位十进制，判断时又溢出

### 代码

```c


int myAtoi(char * str){
    if (str == NULL) return 0;
    
    int i = 0;
    // remove space
    while(str[i] == ' ')
    {
        i++;
    }

    int flag = 1; // + means 1; - means -1;
    if(str[i] == '+')
    {
        flag = 1;
        i++;
    } 
    else if (str[i] == '-') 
    {
        flag = -1;
        i++;
    }
    
    int num;
    str = &str[i];
    i = 0;

    long ret = 0;
    while (i < strlen(str))
    {
        num = str[i] - '0'; // change to NUMBER
        if (num < 0 || num > 9) break; // not NUMBER

        ret = ret*10 + num;
        if (ret > INT_MAX && flag == 1) return INT_MAX;
        else if (ret > INT_MAX && flag == -1) return INT_MIN;
        i++;
    }

    ret *= flag;
    return ret;
}
```