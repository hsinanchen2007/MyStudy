### 解题思路
1、反转字符串
2、排序
3、比较

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for (auto &word: words)
        {
            string tmp(word.rbegin(), word.rend());
            swap(tmp, word);
        }
        sort(words.begin(), words.end());
        int ans = words[words.size() - 1].size() + 1;
        for (int i = words.size() - 2; i >= 0; i--)
        {
            if (words[i + 1].find(words[i]) != 0)
            {
                ans += words[i].size() + 1;
            }
        }
        return ans;
    }
};
```