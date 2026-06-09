### 解题思路
在ASCII码表，大写字母与小写字母相差32

### 代码

```c

char * toLowerCase(char * str){
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] +=32;
        }
    }
    return str;
}