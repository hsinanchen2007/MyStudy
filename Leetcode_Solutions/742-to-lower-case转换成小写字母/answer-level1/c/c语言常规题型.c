### 解题思路
利用ascii码判断。

### 代码

```c


char * toLowerCase(char * str){
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>=65&&str[i]<=90)
        str[i]+=32;
    }
    return str;
}


```