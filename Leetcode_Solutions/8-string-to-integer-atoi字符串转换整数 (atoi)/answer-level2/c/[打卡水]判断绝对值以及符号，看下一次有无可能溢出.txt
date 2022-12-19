### 代码

```c
int myAtoi(char * str){
    int i,num,flagf;
    num=0;flagf=0;
    for(i=0;str[i]&&str[i]==' ';i++); // 第一个非空数字
    if(!str[i]) return 0;   // 全空
    if(str[i]=='-') {i++;flagf=1;} // 负数flagf=1
    else if(str[i]=='+') {i++;} // 正数
    if(str[i]<48||str[i]>57) return 0;  // 非数字
    for(;str[i]<58&&str[i]>47;i++){
        if(num>214748364){
            if(flagf) return -2147483648;
            else return 2147483647;
        }
        if(num==214748364){
            if(flagf&&str[i]>'7') return -2147483648;   //达到边界
            if((!flagf)&&str[i]>'6') return 2147483647;
        }
        num=(num*10+(str[i]-48)); // 更新数值，先减48，不然num*10+str[i]溢出报错
        // printf("%d,",num);
    }
    if(flagf) num=-num;
    return num;
}
```