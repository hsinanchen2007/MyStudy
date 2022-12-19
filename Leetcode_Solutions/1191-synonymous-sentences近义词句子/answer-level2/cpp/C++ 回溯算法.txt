### 解题思路
1. 把近义词数组转换成vector<set<string>>，set中自然是按照字典序排列
2. 把句子字符串转换成vector<string>单词数组
3. 遍历单词数组，如果单词不在任何一个set中，则直接拼接到输出；反之则按set中的顺序回溯

![图片.png](https://pic.leetcode-cn.com/e766b29b01f7a4f6bbe77fe019512400297011df7fbb8401dc68b0ba888d226d-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    vector<string> ans;

    void UpdateSets(vector<string>& words, vector<set<string>>& sets) {
        bool done = false;
        for (set<string>& s : sets) {
            if (s.find(words[0]) != s.end()) {
                s.insert(words[1]);
                done = true;
                break;
            } else if (s.find(words[1]) != s.end()) {
                s.insert(words[0]);
                done = true;
                break;
            } else {
            }
        }
        if (!done) {
            sets.push_back({words[0], words[1]});
        }
    }

    void backtrace(vector<string>& output, int idx, int n, vector<string>& textWords, vector<set<string>>& synonyms_sets) {
        if (idx == n) {
            string t;
            for (int i = 0; i < output.size(); ++i) {
                t.append(output[i]);
                if (i != output.size() - 1) {
                    t.push_back(' ');
                }
            }
            ans.push_back(t);
            return;
        }

        string word = textWords[idx];
        bool hasSyno = false;
        for (set<string> ss : synonyms_sets) {
            if (ss.find(word) != ss.end()) {
                for (string rep : ss) {
                    output.push_back(rep);
                    backtrace(output, idx + 1, n, textWords, synonyms_sets);
                    output.pop_back();
                }
                hasSyno = true;
            }
        }
        if (!hasSyno) {
            output.push_back(word);
            backtrace(output, idx + 1, n, textWords, synonyms_sets);
            output.pop_back();
        }
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        // 把近义词都归到同一个Set里，用vector来装Set
        vector<set<string>> synonyms_sets;
        for (vector<string> v2 : synonyms) {
            UpdateSets(v2, synonyms_sets);
        }
        // 句子拆分成单词数组
        vector<string> textWords;
        string tmpStr;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] != ' ') {
                tmpStr.push_back(text[i]);
            }
            if (text[i] == ' ' || i == text.size() - 1) {
                textWords.push_back(tmpStr);
                tmpStr.clear();
                tmpStr.shrink_to_fit();
            }
        }
        // 回溯所有组合
        vector<string> output;
        backtrace(output, 0, textWords.size(), textWords, synonyms_sets);
        return ans;
    }
};
```