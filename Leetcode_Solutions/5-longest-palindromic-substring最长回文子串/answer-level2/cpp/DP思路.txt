### 解题思路
dp方法，但是一开始觉得一维数组一次遍历就可以，结果弄了半天都pass不了
改2维后，还是要不要想当然，还是需要自己花个表，自己更新一下，坐标更新不都是递增的，而是i是递减的

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
      string res;
      if(s.size() == 0) return res;

      int max_cnt = 1;
      int max_idx = 0;
      vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

      for(int i = 0; i < s.size(); i++){
        dp[i][i] = true;
        if(i + 1 < s.size())
          dp[i][i + 1] = s[i] == s[i + 1];
      }

      for(int i = s.size() - 2; i >= 0; i--){
        for(int j = i + 1; j < s.size() ; j++){
            if(j - 1 >= i + 1)
              dp[i][j] = dp[i + 1][j - 1] & s[i] == s[j];

            if(dp[i][j] && j - i + 1 > max_cnt){
              max_idx = i;
              max_cnt = j - i + 1;
            }
        }
      }


      res = s.substr(max_idx, max_cnt);
      return res;
    }
};
```