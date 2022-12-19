### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        vector<string> reversed_words;
        for (string word : words) {
            reverse(word.begin(), word.end());
            reversed_words.push_back(word);
        }
        sort(reversed_words.begin(), reversed_words.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i+1 < n && reversed_words[i+1].find(reversed_words[i]) == 0) {
            }
            else {
                res += reversed_words[i].length() + 1;
            }
        }
        return res;
    }
};
```