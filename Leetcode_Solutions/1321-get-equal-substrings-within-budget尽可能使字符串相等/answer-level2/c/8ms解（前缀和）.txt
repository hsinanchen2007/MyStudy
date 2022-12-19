首先数组a记录两个字符串相通位置字母差值；
```
for(int i=0;i<n;i++)
    a[i]=abs(s[i]-t[i]);
```
再用数组b记录数组a的前缀和(令数组b首项为0)；
```
b[0]=0;
for(int i=1;i<=n;i++)
    b[i]=b[i-1]+a[i-1];
```
整型p记录从第几个字符开始，p初始值为0；
整型m记录可能的最大长度，m初始值为0；
整体代码如下：
```
int equalSubstring(char * s, char * t, int maxCost){
    int a[100001]={0},n=strlen(s);
    for(int i=0;i<n;i++)
        a[i]=abs(s[i]-t[i]);
    int b[100001]={0};
    b[0]=0;
    for(int i=1;i<=n;i++)
        b[i]=b[i-1]+a[i-1];
    int p=0,m=0;
    for(int i=1;i<=n;i++)
        if(b[i]-b[p]>maxCost){
            p++;
            m=i-p>m?i-p:m;
        }
    return m>n-p?m:n-p;
}

```
