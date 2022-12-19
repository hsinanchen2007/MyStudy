## 暴力法
首先看暴力法的代码
`word1="horse", word2="ros"`
总共有三个允许的操作
+ 插入一个字符，相当于比较`word1`和`word2.substr(1)`
+ 删除一个字符，相当于比较`word1.substr(1)`和`word2`
+ 替换一个字符，相当于比较`word1.substr(1)`和`word2.substr(1)`

根据上面思路，暴力枚举所有情况，时间复杂度是O(3^n)
```cpp
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        return (int)_minDistance(word1.c_str(), word2.c_str());
    }
private:
    size_t _minDistance(const char* s1, const char* s2) {
        if (*s1 == '\0' || *s2 == '\0') {
            return *s1 == '\0' ? strlen(s2) : strlen(s1);
        }
        size_t insert_char = _minDistance(s1, s2 + 1);
        size_t delete_char = _minDistance(s1 + 1, s2);
        size_t replace_char = _minDistance(s1 + 1, s2 + 1);
        size_t ret = std::min(insert_char, std::min(delete_char, replace_char)) + 1;
        if (*s1 == *s2) {
            ret = std::min(ret, replace_char);
        }
        return ret;
    }
};
```
## 动态规划
上面代码有很多重复计算，比如`word1="horse", word2="ros"`部分递归计算过程，标记`*`的过程就是重复计算的
```
word1="horse", word2="ros" #初始状态
word1="horse", word2="os" #插入
word1="orse", word2="ros" #删除         
word1="orse", word2="os" #替换          *
...

word1="horse", word2="os" #初始状态
word1="horse", word2="s" #插入
word1="orse", word2="os" #删除          *
word1="orse", word2="s" #替换
```
为此想到动态规划，将子问题的计算过程保存下来
使用`dp[i][j]`表示`word1.substr(i)`和`word2.substr(j)`的最小编辑距离
那么`dp[i][j]`等于插入，删除和替换操作的最小值加本次操作
插入为`dp[i][j+1]`
删除为`dp[i+1][j]`
替换为`dp[i+1][j+1]`
在代码实现上需要注意我们当`i=len1-1`或者`j=len2-1`时的处理，因此需要在`dp`矩阵各加一行和一列，代码如下
```cpp
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        size_t len1 = word1.size();
        size_t len2 = word2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));
        for (size_t i = 0; i <= len2; ++i) {
            dp[len1][i] = (int)(len2 - i);
        }
        for (size_t i = 0; i <= len1; ++i) {
            dp[i][len2] = (int)(len1 - i);
        }
        for (size_t i = len1; i > 0; --i) {
            for (size_t j = len2; j > 0; --j) {
                dp[i - 1][j - 1] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i][j])) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i - 1][j - 1] = std::min(dp[i - 1][j - 1], dp[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
```