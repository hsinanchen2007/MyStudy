
### 代码

```c
int lengthOfLastWord(char * s){
    if(strlen(s)==0) return 0;
    int i=strlen(s)-1,k=0;
    while(i>=0&&s[i]==' ') i--;//从末尾找到字母
    while(i>=0&&s[i]!=' ') {//从此开始计算连续的字母
        k++;
        i--;
    }
    return k;

}
```