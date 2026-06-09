求两个序列中符合条件的序列数，并且序列的位数比较小，很容易看出来这是个数位dp比较裸的题目。我们发现转移的时候如果当前已经匹配到的字符失配了，那么不能把匹配的位数清零，而应该去找能匹配的最大前缀，所以就是一个kmp匹配问题，求个next数组就行了。
状态为:dp[pos][wei][ok][limit]当前处理到pos位待匹配第wei位 前面有没有匹配成功过ok，上限限制up
后面发现ok其实没必要 因为wei可以当匹配成功的时候直接返回0，等于白加了常数2，还跑满了dp，自然就慢一点。
ps:比赛的时候:evil[j]-'a'==i没有减a找到结束都没找出来，不愧是我。。

```
class Solution {
public:
        typedef long long ll;
        const int mod=1e9+7;


         int nxt[600];
        void getnxt(string t){
        	int j=-1;
            nxt[0]=-1;
	        for(int i=1;i<t.size();i++){
                while(j!=-1&&t[i]!=t[j+1]){
                    j=nxt[j];
                }
                if(t[j+1]==t[i])j++;
                nxt[i]=j;
	        }
        }

        ll add(ll a,ll b){
            a=(a+mod)%mod;
            b=(b+mod)%mod;
            return (a+b+mod)%mod;
        }
        ll dp[600][600][3][3];
        ll a[605];
        ll dfs(int pos,int wei,int ok,bool limit,string&evil){
        if(pos==-1) return ok==0;
        if(dp[pos][wei][ok][limit]!=-1)return dp[pos][wei][ok][limit];
        ll ans=0;
        int up=limit?a[pos]:25;
        for(int i=0;i<=up;i++){
                if(evil[wei]-'a'==i)ans=add(ans,dfs(pos-1,wei+1,(wei+1)==evil.size()||ok,limit&&i==up,evil));
                else {

                    int j=wei-1;
                        while(j!=-1&&evil[j+1]-'a'!=i)j=nxt[j];
                        if(evil[j+1]-'a'==i)j++;
                        if(j+1==evil.size())continue;
                        ans=add(ans,dfs(pos-1,j+1,ok,limit&&i==up,evil));
                }
        }
        return dp[pos][wei][ok][limit]=ans;
    }

    ll solve(string x,string evil){
      int pos=0;
      memset(dp,-1,sizeof(dp));
        for(int i=x.size()-1;i>=0;i--){
            a[pos++]=x[i]-'a';
        }
      return dfs(pos-1,0,0,1,evil);
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        if(s1>s2)return 0;
        if(s1.size()==0)return 0;
        getnxt(evil);
        int flag=1;
        if(s1.find(evil)!=s1.npos){
            flag=0;
        }
        return add(add(solve(s2,evil),-solve(s1,evil)),flag);
    }
};
```
