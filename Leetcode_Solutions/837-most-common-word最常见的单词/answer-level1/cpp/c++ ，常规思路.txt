### 解题思路
这种题，自己一直需要判断是否是末尾
如果有一种方法不这样就好了

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        if (paragraph.empty()) {
            return "";
        }
        unordered_map<string, int> dict;
        string str;
        for (int i = 0; i < paragraph.size(); ++i) {
            if (isalpha(paragraph[i]) || i == paragraph.size() - 1) {
                if (i == paragraph.size() - 1) {
                    if (isalpha(paragraph[i])) {
                        str.push_back(ToLower(paragraph[i]));
                    }
                    dict[str] += 1;
                    break;
                }
                str.push_back(ToLower(paragraph[i]));
            } else {
                dict[str] += 1;
                str.clear();
                while (i < paragraph.size() && !isalpha(paragraph[i])) {
                    i += 1;
                }
                i -= 1;
            }
        }
        for (auto str : banned) {
            dict[str] = 0;
        }
        int max_val = 0;
        for (auto iter : dict) {
            if (iter.second > max_val){
                max_val = iter.second;
                str = iter.first;
            }
        }
        return str;
    }
    void UnionStr(string& str) {
        string temp;
        for (auto ch : str) {
            if (isalpha(ch)) {
                temp.push_back(ToLower(ch));
            }
        }
        str = temp;
    }
    char ToLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
        }
        return ch;
    }
};
```