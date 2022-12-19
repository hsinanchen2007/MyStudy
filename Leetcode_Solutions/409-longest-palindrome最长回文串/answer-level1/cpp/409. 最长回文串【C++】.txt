### 解题思路

解题思路还是很容易想到的，回文串的特征很明显，就是左右对称，也就是说只有正中可能存在单个的字符，其余的字符都一定是偶数个。

所以我很快就想到了统计字符串中不同字符的个数，使用了一个 `vector<pair<char, int>>` 类型的数组 `count` 用于保存每个字符及其对应的个数。

然后遍历 `count` 将每个字符的最多可能取到的偶数个数加到 `length` ，然后为了尽可能的让回文串的长度更长，所以如果存在计数个数的字符，那就应该再+1，即表示将一个单个的字符作为回文串的正中的字符。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int length = 0;
        //统计每个字符的个数
        vector<pair<char, int>> count;
        for (auto c : s) {
            bool exist = false;
            for (int i = 0; i < count.size(); i++) {
                if (c == count[i].first) {
                    count[i].second++;
                    exist = true;
                }
            }
            if (exist == false) {
                count.push_back({ c,1 });
            }
        }
        bool b = false;//判断是否有奇数个数的字符
        for (auto co : count) {
            if (co.second % 2 == 0) {
                length += co.second;
            }
            else {
                if (b == false) {
                    length += co.second;
                    b = true;
                }
                else {
                    length += co.second - 1;
                }
            }
        }
        return length;
    }
};
```