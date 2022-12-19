### 解题思路
说实话 我自己都不是很清楚我的代码
找规律
1101 
1110
111
1000
100
10
1

10101
10110
1011
1100
110
11
100
10
1
把问题化成 非末端0去掉 每次需要+1   

### 代码

```c
int numSteps(char * s){
    int num=0;
    int len=strlen(s);
    if(len==1)
        return 0;
    int k=0,jilu=0,k1=0;
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='1')
            jilu=1;
        if(jilu==1&&s[i]=='0')
            k++;
        if(s[i]=='0')
            k1++;
    }
    if(k==0&&s[len-1]=='0')
    {
        if(len-k1==1)
            return k1;
        else
            return len+1;
    }
    return k+len+1;
}
```