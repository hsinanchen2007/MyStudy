### 解题思路
get到的新东西：
calloc()函数生成未初始化的数组都用0填充。（两个参数）
malloc()函数则为垃圾数据。（一个参数）
数字（0-9）的ASCII码减去'\0'(48) 变为int的0；
新的遍历字符串的方式for(len=0;s[len],len++);
此方式得到的len为'\0'位置。所以直接用于申请内存。

### 代码

```c
char * freqAlphabets(char * s){
    int len=strlen(s);
    int cnt=0;
    char *p=(char*)calloc(sizeof(char),len+1);
    for(int i=0;s[i];)
    {
        if((i+2)<len&&s[i+2]=='#')              //双数位置
        {
            p[cnt++]=(s[i]-48)*10+s[i+1]-48+96;
            i+=3;
        }
        else                                    //单数位置
        {
            p[cnt++]=s[i]-48+96;
            i++;
        }
    }
    return p;
}


```