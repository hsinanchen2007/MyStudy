### 解题思路
C++ 用时和内存击败100%
从一个点到另一个点的指令根据他们的下标之差得到，其他字母到字母z的走法需要特殊处理一下，先往左再往下，防止走出范围
### 代码

```cpp
class Solution {
public:
    void genInstrBetweenTwoChar(char start, char end, map<char, pair<int, int>>& char2pos, string& res) {
        int row_diff = char2pos[end].first - char2pos[start].first;
        int col_diff = char2pos[end].second - char2pos[start].second;
        if (end == 'z') {
            for (int i = 0; i > col_diff; i--) {
                res += "L";
            }
            for (int i = 0; i < row_diff; i++) {
                res += "D";
            }
        } else {
            if (row_diff > 0) {
                for (int i = 0; i < row_diff; i++) {
                    res += "D";
                }
            }
            if (row_diff < 0) {
                for (int i = 0; i > row_diff; i--) {
                    res += "U";
                }
            }
            if (col_diff > 0) {
                for (int i = 0; i < col_diff; i++) {
                    res += "R";
                }
            }
            if (col_diff < 0) {
                for (int i = 0; i > col_diff; i--) {
                    res += "L";
                }
            }
        }
        res += "!";
        return;
    }
    string alphabetBoardPath(string target) {
        string res;
        map<char, pair<int, int>> char2pos;
        for (int i = 0; i < 26; i++) {
            char2pos['a' + i] = make_pair(i / 5, i % 5); //建立字符与其下标的hash
        }
        genInstrBetweenTwoChar('a', target[0], char2pos, res);
        for (int i = 1; i < target.length(); i++) {
            genInstrBetweenTwoChar(target[i - 1], target[i], char2pos, res);
        }
        return res;
    }
};
```