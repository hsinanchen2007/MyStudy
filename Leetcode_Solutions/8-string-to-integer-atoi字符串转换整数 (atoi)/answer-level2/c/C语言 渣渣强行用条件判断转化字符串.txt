### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
    double cnt=0;
    int i,j=0,k=1;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==' '&&j==0) continue;
        else if(str[i]=='-'&&str[i+1]>='0'&&str[i+1]<='9'&&j==0) k=-1;
        else if(str[i]=='+'&&str[i+1]>='0'&&str[i+1]<='9'&&j==0) k=1;
        else if(!(str[i]>='0'&&str[i]<='9')&&j==0) break;
        else if(str[i]>='0'&&str[i]<='9')
        {
            cnt=cnt*10+(str[i]-'0');
            if(cnt>2147483647&&k==1) cnt=2147483647;
            j=1;//做个标记
        }
        else if((str[i-1]>='0'&&str[i-1]<='9')&&!(str[i]>='0'&&str[i]<='9')) break;  
    }
    cnt=cnt*k;
    return cnt;
}
```