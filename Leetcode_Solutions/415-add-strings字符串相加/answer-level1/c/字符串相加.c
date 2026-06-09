### 解题思路
常规思路，逐位相加，模拟进位
有道类似的题，叫二进制字符串相加。代码大同小异
### 代码

```c
char * addStrings(char * num1, char * num2){
    int len_num1,len_num2,i,j,k,carry;
    len_num1=strlen(num1);len_num2=strlen(num2);
    if(len_num1<len_num2) return addStrings(num2,num1);
    char *res=(char*)malloc(sizeof(char)*(len_num1+2));
    res[len_num1+1]='\0';
    i=len_num1-1;j=len_num2-1;carry=0;k=len_num1;
    for(;i>=0||j>=0;){
        int x1,x2,sum;
        x1=i>=0?num1[i]-'0':0;
        x2=j>=0?num2[j]-'0':0;
        sum=x1+x2+carry;
        res[k--]=sum%10+'0';
        carry=sum/10;
        if(i>=0)i--;
        if(j>=0)j--;
    }
    if(carry==0) return res+1;
    res[0]='1';
    return res;
}
```