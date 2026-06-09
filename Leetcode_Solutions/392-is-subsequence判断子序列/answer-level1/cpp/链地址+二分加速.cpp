### 解题思路
参考[@zzzzzz-5](/u/zzzzzz-5/)大佬的题解，主要利用了子序列在原字符串中下标递增的特点，主要有两个要点：1.利用类似于链地址的思想，将每个字母的下标按天然的增序串起来，方便查询；2.用二分可以加速查找，体现在代码里是STL中的upper_bound（在指定范围内查找第一个比指定元素大的位置，返回迭代器）。

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(26);
        for(int i = 0; i < t.size(); ++i) dp[t[i] - 'a'].push_back(i);
        int tag = -1;
        for(auto c:s) {
            int i = c - 'a';
            int j = upper_bound(dp[i].begin(), dp[i].end(), tag) - dp[i].begin();
            if(j >= dp[i].size()) return false;
            tag = dp[i][j];
        }
        return true;
    }
};
```