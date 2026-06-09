### 解题思路
此处撰写解题思路

### 代码

```c
int * count_next(char *s){
    int *next = (int *)malloc(sizeof(int)*(strlen(s)+1));
    next[0]=-1;
    next[1]=0;
    for(int i=2;i<strlen(s)+1;i++){
        int k = next[i-1];
        while(k!=-1&&s[k]!=s[i-1])
            k=next[k];
        next[i]=k+1;
    }
    return next;
}   

bool repeatedSubstringPattern(char * s){
    int N = strlen(s);
    int * next = count_next(s);
    int X = N-next[N];
    if(N%X==0&&N!=X)
        return true;
    return false;
}
```