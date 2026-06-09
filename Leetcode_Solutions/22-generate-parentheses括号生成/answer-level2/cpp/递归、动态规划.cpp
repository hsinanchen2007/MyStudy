### 解题思路
这题很明显可以递归，只需要求得n-1的所有情况，然后将最后一对括号插入其中即可，至于怎么求得n-1时的情况，那不用管，递归即可。
- 递归最关键的是要找到初始状态，然后找到前后2个状态之间的关系，这个多练就会有感觉了。
通过n-1求n，这个又跟动态规划很像，自然就联想到了动态规划，动态规划主要是难想状态转移方程：dp[i]="("+dp[j]+")"+dp[i-j-1];其中0<=j<i。
下面是递归和动态规划提交的截图，上面的是dp，下面的是递归，但是没想到的是递归用的空间居然比动态规划多，应该是多了map的空间
![5.png](https://pic.leetcode-cn.com/3d3d2b27bb3ed9ccc40be4b24409a70803ba30cf61b0e35a7e9705b075f1dddf-5.png)


### 代码
递归代码
```
class Solution {
public:
    map<string,int>mp;
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        if(n==1) return {"()"}; 
        vector<string>ans=generateParenthesis(n-1);
        vector<string>res;
        int len=(n-1)*2;
        for(auto str : ans)
        for(int i=0;i<=len;i++){
            string s;
            s+=str;
            s.insert(i,"(");
            int l=0,r=0;
            for(int j=i+1;j<=s.length();j++){
                if(l==r){
                    string ss;
                    ss+=s;
                    ss.insert(j,")");
                    if(mp.count(ss)==0){
                        res.push_back(ss);
                        mp[ss]=1;
                    }
                }
                if(s[j]=='(') l++;
                else r++;
            }
        }
        ans.erase(ans.begin(),ans.end());
        return res;
    }
};
```
动态规划
```cpp
class Solution {
public:
    //map<string,int>mp;
    vector<string> generateParenthesis(int n) {
        if(n==0) return {};
        vector<vector<string>>dp(n+1);
        dp[1]={"()"};
        for(int i=2;i<=n;i++){
            for(auto k : dp[i-1]){
                string s;
                s+="()";
                s+=k;
                dp[i].push_back(s);
            }
            for(int j=1;j<i;j++){
                for(auto k : dp[j]){
                    string s;
                    s+="(";
                    s+=k;
                    s+=")";
                    if(i-j-1==0){
                        dp[i].push_back(s);
                    }
                    else
                    for(auto ss : dp[i-j-1]){
                        string str;
                        str+=s;
                        str+=ss;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};
```