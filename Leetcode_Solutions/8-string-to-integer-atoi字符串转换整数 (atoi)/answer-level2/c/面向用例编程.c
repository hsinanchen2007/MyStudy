### 解题思路
C代码，面向用例编程

### 代码

```c
int myAtoi(char * str){
    int i = 0;
    int beginflag = 0;
    long num = 0;
    int subflag = 0;
    char last = '0';
    char current;
    while(*(str+i) != '\0')
    {
        current= *(str+i);
        if (!beginflag && (current <'0' || current>'9') && (current != ' ') && (current != '-')&& (current != '+')) break;
        if ((last == '+' && (current <'0' || current>'9')) || (last == '-' && (current <'0' || current>'9'))) break;
        if(beginflag && (current <'0' || current>'9')) break;
        if (current == '-') subflag = 1;
        if (current>='0' && current<='9')
        {
            beginflag = 1;
            num = num*10 + (int)current-48;
            if (num > 2147483648) break;
        }
        i++;
        last = current;
    }
    return subflag ? (-num < -2147483648? -2147483648:-num):(num > 2147483647? 2147483647:num);
}
```