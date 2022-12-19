没想到什么巧妙的解法，按照题目给出的几种情况分类写出每行的处理方法即可。
ans保存结果，begin保存当前行首个单词在words中的位置，width保存当前行所有单次的总宽度。

需要处理的行分为3种：
1. 非末尾行，有一个以上单词。通过单词总数和剩余空格数分配每两个单词间的空格数。
2. 非末尾行，仅有一个单词。该单词靠左填入行中，右侧由空格补齐。
3. 末尾行。每个单词间有一个空格，空出的右侧由空格补齐。

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int begin = 0, width = 0;
        for (int i = 0; i < words.size(); i++) {
            if (width + words[i].size() + i - begin - 1 >= maxWidth) {
                ans.push_back("");
                if (i - begin <= 1) {
                    ans.back() += words[begin];
                    ans.back() += string(maxWidth - ans.back().size(), ' ');
                } else {
                    int quo = (maxWidth - width) / (i - begin - 1);
                    int rem = (maxWidth - width) % (i - begin - 1);
                    for (int j = begin; j < i - 1; j++) {
                        ans.back() += words[j];
                        ans.back() += string(j < begin + rem ? quo + 1 : quo, ' ');
                    }
                    ans.back() += words[i - 1];
                }
                begin = i;
                width = 0;
            }
            width += words[i].size();
        }
        ans.push_back("");
        for (int i = begin; i < words.size() - 1; i++) {
            ans.back() += words[i];
            ans.back() += ' ';
        }
        ans.back() += words.back();
        ans.back() += string(maxWidth - ans.back().size(), ' ');
        return ans;
    }
};
```