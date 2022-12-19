先大致说一下思路，对于一串数，比如说 123456,他们的方法的计算方法，肯定必然是第一个数单独，第一二个数配

对。写完后参考了一下其他大佬得解释，比如你要从家到深圳去，你可以路过长沙或者北京再去深圳。其中长沙有6种

方式去深圳，北京有5种方式，那么总方式就有5+6==11种。

用数学方程可得：

Y(N)=Y(N-1)+Y(N-2);其实写得并不够严谨，这里需要考虑数字，大概的意思能够说的明白。接下来我会在代码种说

清楚，并且分析重要代码对于边界和特殊情况的处理。

解法一（递归）：


```
int numDecodings(char * s){
    int length=strlen(s),count=0;
    if(s[0]=='0')//处理给的数字是0的情况，因为0没有对应的方法。
    return 0;
    if(length<2)
    return 1;
    else//大于等于2
    {
        if((s[0]-'0')*10+(s[1]-'0')<=26)//这里比如满足数小于26才能够调用
        count+=(numDecodings(s+2));
        count+=numDecodings(s+1);
       //count+=numDecodings(s+3); 

    }
    return count;
}
```

对于递归能够解决的，常常要去思考是否能够用动态规划解决，动态规划所要求的时间通常会大大减少。减少时间的

本质在于动态规划是用数组把过程中算过的值保存下来了，那么再次计算的时候就会减少重复计算。

方法二（动态规划）：
```
int numDecodings(char * s){
    int length=strlen(s);
    int dp[length+1],i;
    memset(dp,0,sizeof(int)*(length+1));
    if(s[0]=='0')//考虑给的是0的情况。
    return 0;
    dp[0]=1;
    if(s[length-1]!='0')
    dp[1]=1;
    for(i=2;i<=length;i++)
    {
        if(s[length-i]=='0')//判断首位是0的情况，这里其实对于的是单独给的0的情况
        continue;
        int tmp=(s[length-i]-'0')*10+(s[length-i+1]-'0');
        if(tmp<=26&&tmp)
            dp[i]=dp[i]+dp[i-2];
        dp[i]=dp[i]+dp[i-1];

    }
    //dp[length+1]='\0';
    return dp[length];
}
```
