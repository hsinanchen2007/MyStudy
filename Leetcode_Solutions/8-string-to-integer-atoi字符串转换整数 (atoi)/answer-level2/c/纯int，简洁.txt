### 解题思路
+422     422
-4458    -4458
+442+456 442
-89+897  89
dsf25    0
-we258   0
遇到符号，数字要紧跟在符号后面
遇到数字，连续记录到不是数字为止

### 代码

```c
int myAtoi(char * str){
    int deal(char a[],int n,int num,int flag);
    int i,n=0;
    int num=0;
    while(str[n]==' '&&str[n]!='\0'){
        n++;
    }
    if(str[n]=='+'){
        num=deal(str,n,num,1);
        return num;
    }
    if(str[n]=='-'){
        num=deal(str,n,num,0);
        if(num==-2147483648) return num;
        return -num;
    }
    if(str[n]>='0'&&str[n]<='9'){
        num=num*10+(str[n]-'0');
        num=deal(str,n,num,1);
        return num;     
    }
    return 0;
}

int deal(char a[],int n,int num,int flag){
        n++;
        while(n<strlen(a)&&a[n]>='0'&&a[n]<='9'){
            if(num>214748364) {
                if(flag==1) return 2147483647;
                if(flag==0) return -2147483648;
            }
            if(num==214748364){
                if((a[n]-'0')<8) {
                    num=num*10+(a[n]-'0');
                    return num;
                }
                if((a[n]-'0')>=8){
                    if(flag==1) return 2147483647;
                    if(flag==0) return -2147483648;
                }
            }
            num=num*10+(a[n]-'0');
            n++;
        }
        return num;
}
```