很容易犯错，需要耐心慢慢匹配查找

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int rowPos = 0;
        vector<string> row;
        for (int i = 0; i < words.size(); i ++) {
            // 如果到需要换行的位置
            if (rowPos + words[i].size() > maxWidth) {
                // 根据row生成当前行
                rowPos --;
                int totalGap= maxWidth - rowPos;
                string currentRow = "";
                for (int j = 0; j < row.size(); j++) {
                    // 空行分配不均匀情况下，优先分配左边
                    int gapNum = row.size() - 1;
                    if (gapNum > 0) {
                        if (j < totalGap % gapNum) {
                            currentRow += row[j];
                            currentRow.append(totalGap / gapNum + 2, ' ');
                        } else {
                            currentRow += row[j];
                            if(j != row.size() - 1) currentRow.append(totalGap / gapNum + 1, ' ');
                        }
                    } else {
                        currentRow += row[j];
                        currentRow.append(maxWidth - currentRow.size(), ' ');
                    }
                }
                res.push_back(currentRow);
                row.clear();
                rowPos = 0;
            }
            rowPos += words[i].size() + 1;
            row.push_back(words[i]);
        }
        // 最后一文本的最后一行应为左对齐，且单词之间不插入额外的空格
        if(row.size() > 0) {
            string lastRow = "";
            for(int i = 0; i < row.size(); i ++) {
                lastRow += row[i];
                if(i != row.size() - 1) lastRow += " ";
            }
            lastRow.append(maxWidth - lastRow.size(), ' ');
            res.push_back(lastRow);
        }
        return res;
    }
};
```