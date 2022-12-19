### 解题思路
此处撰写解题思路

### 代码

```c
int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i ,j ,k,t,tap=0;
    if(!sSize) return 0;
    for(i=0;i<gSize-1;i++){
        k=i;
        for(j=i+1;j<gSize;j++){
            if(g[k]>g[j]) k=j;
        }
        if(k!=i){
            t=g[k];
            g[k]=g[i];
            g[i]=t;
        }
    }
    for(i=0;i<sSize-1;i++){
        k=i;
        for(j=i+1;j<sSize;j++){
            if(s[k]>s[j]) k=j;
        }
        if(k!=i){
            t=s[k];
            s[k]=s[i];
            s[i]=t;
        }
    }
    if(s[sSize-1]<g[0]) return 0;
    for(i=0;i<sSize;i++)   if(s[i]>=g[0]) break;
    for(tap=0;tap<gSize&&(i+tap)<sSize;){
        if(s[i+tap]>=g[tap]){
            tap++;
        }
        else i++;
    }
    return tap;
}
```