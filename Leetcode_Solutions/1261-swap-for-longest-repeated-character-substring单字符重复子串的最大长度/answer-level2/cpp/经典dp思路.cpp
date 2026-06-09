```
//执行用时 :68 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int res=1,rec;
    bool flag;
    char ch;
    unordered_map<char,int> list;
    int maxRepOpt1(string text) {
        for(auto& it: text) list[it]++;
        int dp[text.size()];
        for(auto& it: list) {
            if(it.second==1) continue;
            ch = it.first;
            memset(dp,0,sizeof(dp));
            flag = text[0]==ch;dp[0] = 1;
            for(int i=1;i<text.size();i++) {
                if(text[i]==ch) dp[i] = dp[i-1] + 1;
                else {
                    if(flag) {
                        dp[i] = dp[i-1] + 1;
                        rec = i;
                        flag = false;
                    }else {
                        dp[i] = i - rec;
                        rec = i;
                    }
                }
                res = max(res,min(dp[i],list[ch]));
            }
        }
        return res;
    }
};
```
