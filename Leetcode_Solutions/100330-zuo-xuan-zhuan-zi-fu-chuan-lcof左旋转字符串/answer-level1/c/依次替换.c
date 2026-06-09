### 解题思路
此处撰写解题思路
注意可以strlen(s)获得字符串长度
### 代码

```c
char* reverseLeftWords(char* s, int n){
    if(s==0) return 0;
    int len=strlen(s);
    while(n>0){
        int temp=s[0];
        for(int i=0;i<=len-2;i++){
            s[i]=s[i+1];
        }
        s[len-1]=temp;
        n--;
    }
    return s;
}
```