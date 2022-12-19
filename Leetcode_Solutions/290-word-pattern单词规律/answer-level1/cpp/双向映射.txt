### 解题思路
观察题目，首先需要一个映射表(char->str)，用于存储匹配字符与单词的映射关系，
每次单词出现时，需要查找该单词是否映射过，故需要另一个映射表(string --> char)，
1. 如果当前单词以映射过，但对应的pattern字符不匹配，则退出
2. 如果当前单词未被映射，则在两个hash表中分别加入映射
3. 当前单词处理完毕之后，需要根据pattern规则，预测下一个word，此时需根据下一个pattern字符，查找是否有该字符对应的word

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() && !str.empty()) {
            return false;
        }

        map<char, string> cm;
        map<string, char> wm;
        int wc = 0;
        int sz = str.size(), psz = pattern.size();
        int start = 0;
        string next_word;
        for (int i = 0; i < sz; ++i) {
            if (psz <= wc) {
                return false;
            }
            if (str[i] == ' ' || i == sz - 1) {
                string word = (i == sz - 1) ? str.substr(start, i - start + 1) : str.substr(start, i - start);
                start = i + 1;
                if (!next_word.empty()) {
                    if (word != next_word) {
                        return false;
                    }
                }else {
                    auto iter = wm.find(word);
                    char c = pattern[wc];
                    if (iter != wm.end()) {
                        if (iter->second != c) {
                            return false;
                        }
                    } else {
                        wm[word] = c;
                        cm[c] = word;
                    }
                }
                if (wc + 1 < psz) {
                    char next_char = pattern[wc + 1];
                    auto it = cm.find(next_char);
                    next_word = (it != cm.end()) ? it->second : "";
                }
                ++wc;
            }
        }

        if (wc != psz) {
            return false;
        }

        return true;
    }
};
```