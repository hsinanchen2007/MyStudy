### 解题思路
注意2点：**每次**拼写时，chars 中的每个字母都只能**用一次**。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> charMap;
        for (char c: chars) {
            charMap[c]++;
        }
        int res = 0;
        for (string word : words) {
            unordered_map<char, int> wordMap;
            for (char c: word) {
                wordMap[c]++;
            }
            bool flag = true;
            for (char ch : word) {
                if (wordMap[ch] > charMap[ch]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res += static_cast<int>(word.size());
            }
        }
        return res;
    }
};
```