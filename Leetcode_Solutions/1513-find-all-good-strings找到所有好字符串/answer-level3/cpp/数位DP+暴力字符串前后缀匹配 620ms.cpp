```
class Solution {
public:

    int g[510];//用于存储各个数位
    int dp[510][51],mod;//dp[i][j]表示，当前剩余位数为i/高位为i～已经和evil匹配了j个字符 的好字符串个数
    string evilStr;//evilStr=evil
    char stk[510];//dfs遍历所得的当前字符串
    //(当前数位为len/即剩余位数为len+1;已经和evil匹配了s位;上一位是否为上限;搜索深度)
    int dfs(int len,int s,bool f,int dep)
    {
        if(len<0)
            return 1;//0位搜索结束，证明是个好字符串
        if(!f&&dp[len][s]!=-1){
            return dp[len][s];//不受限 且 已知 剩余len位数时匹配了s位的结果，直接返回答案
        }
        int fmax=f?g[len]:'z';
        int cur=0;
        for(int i='a';i<=fmax;i++)
        {
            if(s==evilStr.length()-1&&i==evilStr[evilStr.length()-1]){////evil的最后一位也匹配上了
                continue;////坏字符串
            }
            
            stk[dep] = i;
            int ts=0;
            if(i==evilStr[s]){
                ts=s+1;
            }
            else{//字符串evil 匹配 stk的后缀 ，求最大匹配长度// 十分暴力
///此处可以考虑优化成kmp～但是测试数据可能太弱了～暴力也能过
                for(int k=min((int)evilStr.length(),dep + 1);k>0;k--){
                    int flg=1;
                    for(int j=0;j<k;j++){
                        if(stk[dep+1-k+j]!=evilStr[j]){
                            flg=0;
                            break;
                        }
                    }
                    if(flg){
                        ts=k;
                        break;
                    }
                }
            }
            
            cur+=dfs(len-1,ts,f&&(i==fmax),dep+1);
            if(cur>=mod){
                cur-=mod;
            }
        }
        if(!f)
            dp[len][s]=cur;
        return cur;
    }
    int solve(string str)
    {
        int len=str.length();
        for(int i=0;i<len;i++){
            g[i]=str[len-1-i];//g记录str的反向。g下标0为个位，1为十位，2为百位...
        }
        memset(dp,-1,sizeof dp);
        return dfs(len-1,false,true,0);
        //(数字最高位下标为length-1;已经和evil匹配了0位;受限;搜索深度)
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        mod=1e9+7;
        evilStr  = evil;
        int ans=solve(s2)-solve(s1);//查找区间(s1,s2]内的好字符串
        if(s1.find(evil) == string::npos )
        {
            ans++;//evil不是s1的子串，即s1是个好字符串
        }
        ans=(ans%mod+mod)%mod;
        return ans;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c3c47a5eb8ccb1a71b51f4a7055d2eadede6774a093e09ee4b18fdf5a7a7301f-image.png)
//
用kmp还需要注意些细节，debug很久～可能是我太菜了居然跑了1000+ms
数位dp+kmp的版本
https://paste.ubuntu.com/p/KF6kY7mJt9/
