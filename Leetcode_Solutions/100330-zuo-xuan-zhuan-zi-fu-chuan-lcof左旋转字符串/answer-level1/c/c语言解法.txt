### 解题思路
常规解法

### 代码

```c
char* reverseLeftWords(char* s, int n){
    char* num=(char*)malloc(sizeof(char)*(n+1));
    int cnt=0;
    int m=strlen(s);
    for(int i=0;i<n;i++)
    {
        num[i]=s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            s[j]=s[j+1];
        }
    }
    for(int i=m-n;i<m;i++)
    {
        s[i]=num[cnt++];
    }
    return s;
}
```