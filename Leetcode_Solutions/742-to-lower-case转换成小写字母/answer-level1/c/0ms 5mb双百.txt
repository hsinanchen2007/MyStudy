### 解题思路
做个日志大佬们无视我

### 代码

```c
char * toLowerCase(char * s){
    int i=0;
    while(s[i]!=0){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
        i++;
    }
    return s;
}
```