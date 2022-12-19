# 写一个 前缀和数组&&后缀和数组，然后，暴力每一位连续的最大和，稍微特判一下，就ac了

```
class Solution {
public:
    int ans=0,maxn=0,sum1[20004],sum2[20005],vis[160];
    int maxRepOpt1(string text) {
        int cnt=1,len=text.size();
        sum1[0]=1,sum2[len-1]=1;
        vis[text[0]]=1;
        for(register int i=1;i<len;++i){
            vis[text[i]]++;
            if(text[i]==text[i-1])
                sum1[i]=sum1[i-1]+1;
            else
                sum1[i]=1;
            maxn=max(maxn,sum1[i]);
        }
       for(register int i=len-2;i>=0;--i){
            if(text[i]==text[i+1])
                sum2[i]=sum2[i+1]+1;
            else
                sum2[i]=1;
        }
        for(register int i=1;i<len-1;++i){
            if(text[i-1]==text[i+1]){
                int num=sum1[i-1]+sum2[i+1];
                if(num<vis[text[i-1]])
                    num+=1;
                ans=max(ans,num);
            }else if (text[i]!=text[i-1]){
                if(sum1[i-1]<vis[text[i-1]])
                    ans=max(ans,sum1[i-1]+1);
            }
        }
        return max(ans,maxn);
    }
};
```
