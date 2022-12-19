```
int cmp(const void* a,const void* b){
    return *(int*)a>*(int*)b;
}
int min(int a,int b){
    return a<b?a:b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    //从小到大对两个数组排序
    qsort(g,gSize,sizeof(int),cmp);
    qsort(s,sSize,sizeof(int),cmp);
    int j=0,n=0;
    for(int i=0;i<gSize;i++){
        //数组范围内找到满足当前孩子需求的饼干
        while(j<sSize&&s[j]<g[i])
            j++;
        if(sSize==j)
            return n;
        if(s[j]>=g[i]){
            n++;
            j++;
            if(j==sSize)
                return n;
        }
    }
    //sSize-j为剩余的大的饼干数
    return min(gSize,n+sSize-j);
}
```
