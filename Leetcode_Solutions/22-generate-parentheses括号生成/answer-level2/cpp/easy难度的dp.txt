### 解题思路
- 位置i处可以加入两个字符"("or")"
- 加入"("需要前面的字符串的"("数量未到达n
- 加入")"需要前面还存在未被匹配的"("使的括号序列有效
- 仅需要前一个位置的所有字符状态
- 输入："(,{1,1}" // 字符串， 已经存在的左括号， 可以配对的左括号
- 输出：当所有字符 2*n都匹配结束   

### 代码
16ms. 8.9MB
速度慢了点应该是每次申请带来的大量copy
可以采用以空间（空间击败100%）换时间
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        typedef pair<string, pair<int,int>>p; // 字符串， 已经存在的左括号，可以配对的左括号
        if(n == 0) return {""};
        vector<p> dp;// 仅需要前一个状态的所有情况
        dp = {make_pair("(", make_pair(1,1))};
        for(int i=1; i<2*n; ++i){
            vector<p> temp;
            for(auto s:dp){
                if(s.second.first < n) {
                    temp.push_back({s.first+"(",{s.second.first+1,s.second.second+1}});
                } // 可以加入左括号
                if(s.second.second > 0){
                    temp.push_back({s.first+")",{s.second.first,s.second.second-1}});
                }
            }
            dp = temp;
        }
        vector<string> ans(dp.size());
        for(int i=0; i<dp.size(); ++i){
            ans[i] = dp[i].first;
        }
        return ans;
    }
};
```