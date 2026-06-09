**溢出情况的判断：**
**1.用long存储，转int后不等则溢出**
**2.与INT_MAX / 10比较**

```cpp
int myAtoi(char * str){
    /*特判*/
    if(!str || str == "")
        return 0;
    if(str[0] != '+' && str[0] != '-' && str[0] != ' ' && !isdigit(str[0]))
        return 0;

    /*跳过空格并判断*/
    char *p = str;
    while(*p == ' ')
        p++;
    if(!isdigit(*p) && *p != '-' && *p != '+')
        return 0;

    /*转换*/
    //long ans = 0;
    int ans = 0, tmp;
    int negtive = ((*p) == '-') ? 1 : 0;
    if(*p == '-' || *p == '+')
        p++;
    while(isdigit(*p)){
        /*与INT_MAX/10比较*/
        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tmp > 7)){
            return negtive ? INT_MIN : INT_MAX;
        }
        /*用long判断,此时ans要设为long*/
        /*
        if((int)ans != ans){
            return negtive ? INT_MIN : INT_MAX;
        }
        */
        ans = ans * 10 + ((*p) - '0');
        p++;
    }
    return negtive ? -ans : ans;
}
```