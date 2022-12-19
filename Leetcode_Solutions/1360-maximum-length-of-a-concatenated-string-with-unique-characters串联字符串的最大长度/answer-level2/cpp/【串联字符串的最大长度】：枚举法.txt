#### 思路分析

对于每个单词无非就两种情况，选或这不选。

对于 `arr` 中的每个单词我用一个二进制位来表示它，为 1 表示选择这个单词，为 0 表示不选择这个单词。

题目给出 1 <= arr.length <= 16，那一个 int(38位)就足够表示 `arr` 中的所有单词。

例如 `arr` 中有 5 个单词，我用 `int i;` 来枚举对 `arr` 的所有选择情况：

- 当 `i = 0;` 时，`i` 的所有位都为 0 ，表示的情况是： `arr` 中的单词都不选择。

- 当 `i = (1 << 5) - 1` 时，`i` 的前 5 位都为 1，表示的情况是：`arr`中的单词都选择。

那所有选择情况就可以这样枚举：

```cpp
for (int i = 0; i < (1 << 5); i++) {
    // 得到的每个 i 都可以表示一种选择情况
}
```



对于 i 表示的情况，怎么知道某个单词 `word` 的选取状态？

`word` 在 `arr` 中的索引 `j` 就表示它在 `i` 的第几位，使用 `i & (1 << j)` 就知道 `word` 的选取状态。

- 当 `i & (1 << j)` 为 1 时，表示 `word` 的状态为选择；
- 当 `i & (1 << j)` 为 0 时，表示 `word` 的状态为不选。



同时，这里使用位掩码来表示字符串中 26 个英文小写字母的出现情况。在代码中用 `int m;` 中的 26 位，来表示 26 个英文的出现状态。



#### 完整代码

```cpp
class Solution {
public:
    bool isUnique(string& word, int& m) {
        for (char c : word) {
            if (m & (1 << (c-'a'))) {
                return false;
            }
            m |= (1 << (c- 'a'));
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int len = arr.size();
        int ans = 0;
        for (int i = 0; i < (1 << len); i++) {
            int sum = 0;
            int m = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j) && isUnique(arr[j], m)) {
                    sum += arr[j].length();
                }
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```



#### 解释

- `sum` 用来保存每情况下，串联得到字符串的长度。
- `isUnique()` 函数用来判断单词 `arr[j]` 中的字母，是否已经存在与串联字符串中。



#### 最后

感谢您的观看！

欢迎大家留言，一起讨论交流。