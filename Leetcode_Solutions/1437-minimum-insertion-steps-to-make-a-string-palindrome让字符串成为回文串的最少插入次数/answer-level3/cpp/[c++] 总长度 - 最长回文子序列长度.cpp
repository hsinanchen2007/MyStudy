类似题目: 
[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)
[72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)
```
int minInsertions(string s) {
    vector<vector<int>> DP(s.size(), vector<int>(s.size())); // 创建DP数组
    for (int left = s.size()-1; left >= 0; left--) {
        DP[left][left] = 1; // 初始化单个字符回文长度为 1
        for (int right = left + 1; right < s.size(); right++) {
            if (s[left] == s[right]) {
                /**
                    * 左右字符相等 , 则DP[left][right]为除了左右两个字符的最大回文长度加2
                    * 即 [aba] = 1 + [b] + 1
                    */
                DP[left][right] = DP[left + 1][right - 1] + 2; 
            } else {
                /**
                    * 左右字符不相等 , 则DP[left][right]为"除了左字符的串"和"除了右字符的串"的最大回文长度
                    * 即[abc] = max( [bc] , [ab] )
                    */
                DP[left][right] = max(DP[left + 1][right], DP[left][right - 1]);
            }
        }
    }
    return s.size() - DP[s.size()][s.size()];
}
```
