### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
    int a = 1;
    long res = 0;
    long INF_MAX = 2147483647;
    long INF_MIN = -2147483648;

    for (; *str == ' '; str++); //过滤掉有效字符前的所有空格
    switch (*str) { //判断后直接继续，之前把这个部分放在for里面，然后用if判断，
    case 45:         //出现了和Non1TH用户一样的错误， “+-2”得到“2”
        a = -1;
    case 43:
        str++;
    }
    for (; *str; str++) {
        //如果数字后面出现非数字字符，例如“0012a23” 应返回“12”，或者“3.14” 应返回“3”
        if (*str < 48 || *str > 57)
            return ((int)res * a);
        if (*str >= '0' && *str <= '9')
            res = res * 10 + (*str - '0');
        //如果出现数字过大或者过小，及时返回INT_MAX或者INT_MIN
        if ((int)res != res)    
            return (a == -1) ? (INF_MIN) : (INF_MAX);
    }
    return ((int)res * a);
}
```
测试几种易错情况：
“3.1415”  ->  "3"
"012ab12" ->  "12"
"2147483649"  ->  "2147483647"
"+-2"  ->  "0"
大家加油