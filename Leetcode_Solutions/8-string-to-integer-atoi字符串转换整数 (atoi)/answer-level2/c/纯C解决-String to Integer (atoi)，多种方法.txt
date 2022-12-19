### 解题思路
这里给了两种方法，第一种代码量大，但是非常清晰，第二种代码量小。

思路非常清晰，就完全把答案的意思翻译过来即可，具体看代码立即懂
### 代码

```c
//常规方法
int myAtoi(char * str){
    long result=0;
    int length=strlen(str);
    int index=0;

    //删除空格
    while(str[index]==' ')
    index++;
    //判断符号
    int sign=1;
    if(str[index]=='-')//负号
    {
        index++;
        sign=0;
    }
    else if(str[index]=='+')//正号
        index++;
    
    //获取数字
    while(str[index]>='0'&&str[index]<='9')
    {
        result=result*10+str[index]-'0';
        index++;
        if(result>INT_MAX)//防止数据大
        break;
    }
    //添加符号
    if(sign==0)
    result=~result+1;
    
    //判断是否越界
    if(result>INT_MAX)
    return INT_MAX;
    if(result<INT_MIN)
    return INT_MIN;
    return result;

}   
```

```c
//调用库函数
int myAtoi(char * str){
    long long i = 0;
    int ret = sscanf(str, "%lld", &i);
    if (ret) {
        if (i > INT_MAX)
            i = INT_MAX;
        else if (i < INT_MIN)
            i = INT_MIN;
    }
    return (int)i;
}
```
