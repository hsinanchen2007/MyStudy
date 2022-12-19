//中心扩展法
```
int countSubstrings(char * s){

int i,j;
int len=strlen(s);
if(len<=1) return 1;
int sum=0;

for(i=1;i<len;i++)//偶数个回文子串个数
{
    int low=i-1;
    int high=i;
    while(low>=0&&high<len&&s[low]==s[high])
    {
        low--;
        high++;
        sum++;
    }
}
for(i=1;i<len;i++)//奇数个回文子串个数
{
    int low=i-1;
    int high=i+1;
    while(low>=0&&high<len&&s[low]==s[high])
    {
        low--;
        high++;
        sum++;
    }
}
sum+=len;
return sum;
}
```
动态规划
```
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXSIZE 1001
int dp[MAXSIZE][MAXSIZE]={0};

int countSubstrings(char * s){
    
    int i,j,count=0;
    int n=strlen(s);
    memset(dp,0,sizeof(dp));
    for(j=0;j<n;j++)
    {
        for(i=0;i<=j;i++)
        {
            if(j-i<2)//边界条件
              dp[i][j]=(s[i]==s[j]);
            else
              dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);
            if(dp[i][j])
                count++; 
        }
    }
    return count;
}
```

/***********************************************************/
关于马拉车算法的一些理解，首先对字符串进行预处理，使其变成奇数个字符如：aba--->#a#b#a# ,abba--->#a#b#b#a#
然后对每个字符进行循环，求每个字符的回文半径RL[i],然后将RL[i]回文半径/2，依次相加 为回文子串总数。
![image.png](https://pic.leetcode-cn.com/97bbe67bd7298c7b8c05597fbbdfa31c62f68f691511ab65eb9953903dc07611-image.png)
![IMG_20200114_122558.jpg](https://pic.leetcode-cn.com/fe406b0ba39519df80bf3d5090fcebdcef120214f6ab7d70bff66cac6b38a64e-IMG_20200114_122558.jpg)

//马拉车算法
```
class Solution {
public:
    int countSubstrings(string s) {
       if(s.size()<=1) return 1;

       //预处理
       string s1;
       for(int i=0;i<s.length();i++)
       {
           s1+="#";
           s1+=s[i];
       }
       s1+="#";

       int len=s1.length();
       int *RL=new int [len];
       int MaxRight=0,pos=0;

       for(int i=0;i<len;i++)
       {
           //起始半径RL[i]
        if(i<MaxRight)
            RL[i]=min(RL[2*pos-i],MaxRight-i);
        else
            RL[i]=1;

        while(i-RL[i]>=0&&i+RL[i]<len&&s1[i-RL[i]]==s1[i+RL[i]])  
            RL[i]+=1;
        if(RL[i]+i-1>MaxRight)
        {
            MaxRight=RL[i]+i-1;
            pos=i;
        }
       }
       int sum=0;
       //for(int i=0;i<len;i++)
        //  cout<<RL[i]<<" ";
       // cout<<endl;
       for(int i=0;i<len;i++)
          sum+=RL[i]/2;
        return sum;
    }
};
```
