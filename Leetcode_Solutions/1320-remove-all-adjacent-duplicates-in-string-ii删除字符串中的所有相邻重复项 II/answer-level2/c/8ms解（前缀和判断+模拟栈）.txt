字符串a记录最后的结果;
整体思想是判断字符串尾部是否存在连续k个相同字符，只要一直依据这个判断就能够得到最后的解;
数组b记录循环时字符串a的前缀和;
当字符串a的长度>k时进行判断;
如果字符串a中后k项都是s[i]，那么一定满足k*s[i]==(b[n]-b[n-k])，若不满足这个条件，则字符串暂时合法，进行下一次循环;
如果字符串不合法，则把字符串a的长度减少k各单位;
整体代码如下：
```
char * removeDuplicates(char * s, int k){
    int n=0,m=strlen(s);
    char* a=(char*)malloc((m+1)*sizeof(char));
    int b[100001]={0};
    b[0]=0;
    for(int i=0;i<m;i++){
        a[n++]=s[i];
        b[n]=b[n-1]+a[n-1];
        if(n>=k&&k*s[i]==(b[n]-b[n-k])){
            int t=1;
            for(int j=n-k;j<n;j++)
                if(a[n-1]!=a[j]){
                    t=0;
                    break;
                }
            if(t)
                n-=k;
        }
    }
    a[n]='\0';
    return a;
}
```
