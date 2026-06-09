### 解题思路
从末尾找到第一个不是‘\0’ 结束符，也不是‘ ’空格符的最后一个单词词尾，在往前知道到了一个‘ ’或者到-1 输出长度
最开始没有考虑上全是空格情况，若是找尾字母找到-1位置，直接输出0即可

### 代码

```c
int lengthOfLastWord(char * s){

    int last = strlen(s);
    if(last==0) return 0;
    int p=0;
    int i;
    for(i=last;i>=-1;i--)
    {
        if(i==-1) break;
        if(s[i]!='\0'&&s[i]!=' ') break;
    }
    
    if(i==-1) return 0;
    // s[i] 是最后一个单词尾字母
    int num=0;
    while(s[i--]!=' ')
    {
        num+=1;
        if(i==-1) break;
        
    }
    return num;
}
```