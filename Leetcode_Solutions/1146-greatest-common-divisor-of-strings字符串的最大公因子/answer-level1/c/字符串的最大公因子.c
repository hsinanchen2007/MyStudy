### 解题思路
先用字符串复制和字符串连接函数判断是否有最大公因子
用求最大公约数的方法求最大公因子的字符个数
最后赋值即可

### 代码

```c


char * gcdOfStrings(char * str1, char * str2){
    int x,y,i;
    x=strlen(str1);y=strlen(str2);
    char *comp1=(char*)malloc(sizeof(char)*(x+y+1));
    comp1[x+y]='\0';
    char *comp2=(char*)malloc(sizeof(char)*(x+y+1));
    comp2[x+y]='\0';
    strcpy(comp1,str1);
    strcat(comp1,str2);
    strcpy(comp2,str2);
    strcat(comp2,str1);     //str1连接str2的结果与str2连接str1的结果相同
    if(strcmp(comp1,comp2)!=0) return "";
    i=x%y;
    while(i!=0){
        x=y;
        y=i;
        i=x%y;
    }       //求字符个数
    char *res=(char*)malloc(sizeof(char)*(y+1));
    res[y]='\0';
    for(i=0;i<y;i++)res[i]=str1[i];
    return res;
}


```