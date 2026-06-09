### 解题思路
类似于发牌，上下，左右分别对应上，则返回true。

### 代码

```c
bool judgeCircle(char * moves){
    int w=0,s=0,a=0,d=0;
    bool flag=0;
    for(int i=0;i<strlen(moves);i++)
    {
        if(moves[i]=='U')
        w++;
        if(moves[i]=='D')
        s++;
        if(moves[i]=='L')
        a++;
        if(moves[i]=='R')
        d++;
    }
    if(w==s&&a==d)
    flag=1;
    return flag;
}
```