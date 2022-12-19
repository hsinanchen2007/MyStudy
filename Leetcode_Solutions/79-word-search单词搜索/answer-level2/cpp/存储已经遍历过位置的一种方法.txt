### 解题思路
思路就是最普遍的回溯法。在追踪已经考察过的位置，没有用大部分题解里的另外开辟一个m×n的记录表，而是用了一个`vector<pair<int, int>>`，在大大减小空间复杂度的同时（O(mn) -> O(k)，k是查询的字符串数目）没有显著增加时间复杂度（O(k)->O(klogk)）。因为k与m、n相比显著小，所以从均摊意义上讲就大概可以忽略。

### 代码

```cpp
class Solution {
private: 
    int width, height, length;

public:
    bool exist(vector<vector<char>>& board, string word) {
        // 特殊解
        height = board.size();
        if (height == 0) return false;
        width = board[0].size();
        if (width == 0) return false;
        length = word.size();
        if (length == 0) return true;
        vector<pair<int, int>> log;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                if (exist(board, word, log, 0, i, j)) return true;
                log.clear(); // 直接清空记录
            }
        return false;
    }

    bool exist(const vector<vector<char>>& board, const string& word,
               vector<pair<int, int>>& log, int ch, int i, int j) {
        if (ch == length) return true; // 成功判断
        if (i >= height || i < 0 || j >= width || j < 0) return false; // 越界判断
        if (find(log.begin(), log.end(), make_pair(i, j)) != log.end()) return false; // 查询是否已经在路径中
        if (word[ch] != board[i][j]) return false;
        log.push_back(make_pair(i,j)); // 如果没有在路径中且符合，加入路径
        bool res = (exist(board, word, log, ch+1, i+1, j) || 
                    exist(board, word, log, ch+1, i, j+1) || 
                    exist(board, word, log, ch+1, i-1, j) || 
                    exist(board, word, log, ch+1, i, j-1));
        if (!res) log.pop_back();
        return res;
    }
};
```