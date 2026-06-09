### 解题思路
击败96%
出发点前缀和为0 ，此类题都可以解决
### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())return 0;       
        int res = work(s);
        cout << res << endl;
        reverse(s.begin(),s.end());
        for(auto &c : s)c ^= 1;
        return max(res,work(s));
    }
    int work(string& s){
        int maxlen = 0;
        int start = 0;
        int cnt = 0;
        for(int i = 0;i < s.size();++i){
            if(s[i] == '('){
                ++cnt;
            }else{
                --cnt;
            }
            if(cnt == 0){
                maxlen = max(maxlen,i-start+1);
            }
            if(cnt < 0){
                start = i + 1;
                cnt = 0;
            }
        }
        return maxlen;
    }
};
```