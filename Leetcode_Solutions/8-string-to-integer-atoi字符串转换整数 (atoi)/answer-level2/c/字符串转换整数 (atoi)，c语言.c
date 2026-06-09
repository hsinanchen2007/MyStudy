/*字符串实质上是存储着ascii表上字符对应的数字，所以字符可以直接比大小、加减*/
```
int myAtoi(char * str){
    int i=0,mark=0;
    long result=0;
    while(str[i] == ' '){
        i++;
    }
    if(str[i] == '-'){
        i++;
        mark = 1;
    }else if(str[i] == '+'){
        i++;
    }
    while(str[i]>='0'&&str[i]<='9'){
        result = result*10+str[i++]-'0';
        if(result>2147483648){
            result = 2147483648;
            break;
        }
    }
    if(mark == 1){
        result = -result;
    }
    if(result == 2147483648){
        result -= 1;
    }
    return result;
}
```
