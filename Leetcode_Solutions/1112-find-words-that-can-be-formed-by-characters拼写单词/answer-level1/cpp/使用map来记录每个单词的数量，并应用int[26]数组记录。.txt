### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> chars_count = count(chars); // 统计字母表的字母出现次数
        int res = 0;
        for (string& word : words) {
            vector<int> word_count = count(word); // 统计单词的字母出现次数
            if (contains(chars_count, word_count)) {
                res += word.length();
            }
        }
        return res;
    }

// 检查字母表的字母出现次数是否覆盖单词的字母出现次数
    bool contains(vector<int>& chars_count, vector<int>& word_count) {
        for (int i = 0; i < 26; i++) {
            if (chars_count[i] < word_count[i]) {
                return false;
            }
        }
        return true;
    }

// 统计 26 个字母出现的次数
    vector<int> count(string& word) {
        vector<int> counter(26, 0);
        for (char c : word) {
            counter[c-'a']++;
        }
        return counter;
    }
};
```