![image.png](https://pic.leetcode-cn.com/6df7d18e8e231ae44588c676635315e421ab4c64a8b66dcdd311cd3413c4b1e4-image.png)

```
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    vector<string> line;
    string lineOutput;
    int charInLine = 0;
    int wordIndex = 0;
    while (wordIndex < words.size()) {
        bool pendingLine = false;
        if ((charInLine == 0 && words[wordIndex].size() == maxWidth) || // 情况1: 第一个单词完全占满一行
            (charInLine + words[wordIndex].size() < maxWidth)) {        // 情况2: 再加多一个单词就超过一行
            pendingLine = true;  // 这一行可能还要继续加单词
            if (!line.empty()) {
                line.back().push_back(' ');  // 上一个单词后面加一个空格
                ++charInLine;
            }
            line.push_back(words[wordIndex]);
            charInLine += words[wordIndex].size();
            if (++wordIndex == words.size())
                pendingLine = false;  // 单词已用完，不用再添加了
        }
        if (!pendingLine) {
            int spaces = maxWidth - charInLine;
            if (spaces == 0) {
                // 完美占满一行，啥也不做。
            } else if (wordIndex == words.size()) {
                line.back().append(spaces, ' ');  // 最后一行，补满空格
            } else if (line.size() == 1) {
                line[0].append(spaces, ' ');  // 一行仅一个单词，补满空格
            } else {
                int i = 0;
                while (spaces-- > 0) {  // 普通情况: 从头开始顺序加空格（行末单词除外）
                    line[i].push_back(' ');
                    i = (i + 1) % (line.size() - 1);
                }
            }
            
            // 构造一行的 string
            for (string s : line) {
                lineOutput.append(s);
            }
            ans.push_back(lineOutput);
            lineOutput.clear();
            lineOutput.shrink_to_fit();
            line.clear();
            line.shrink_to_fit();
            charInLine = 0;
        }
    }
    return ans;
}
```
