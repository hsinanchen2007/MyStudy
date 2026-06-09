### 解题思路
深度遍历

进入dfs之前进行一个剪枝，优化一下
进入之后，如果发现某个路径上字符与当前字符串的字符不想等，直接返回false
如果`index == words.size() - 1`, 则意味着到字符串的最后一个字符都相等（因为不相等就直接返回false了)，下面的肯定都是满足`board[i][j] == word[index]`, 因此如果`index == word.size() -1`, 则意味着最后一个字符都匹配到了，所以直接返回true
然后分四个方向（如果存在）去进行遍历，先将当前字符置为'#', 四个方向遍历完后，再重置一下
如果任意一个方向返回true, 则直接返回true

### 代码

```cpp
class Solution {
public:
    bool dfs(string& word, int index, int i, int j, vector<vector<char>>& board) {
        
        
        //printf("outside index = %d\n", index);
        // 不能用visited数组，因为之前标记的，之后可能会用到
        if (board[i][j] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            //res = true;
            return true;
        }
        if (board[i][j] == word[index]) { // 这里的判断可以去掉
            
            char tmp = board[i][j];
            board[i][j] = '#';
            if ((i < board.size() - 1 && dfs(word, index + 1, i + 1, j, board))
                || (i > 0 && dfs(word, index + 1, i - 1, j, board))
                || (j < board[0].size() - 1 && dfs(word, index + 1, i, j + 1, board))
                || (j > 0 && dfs(word, index + 1, i, j - 1, board))
                ) {
                
                return true;
            }
            board[i][j] = tmp;
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int height = board.size();
        if (height == 0) {
            return false;
        }
        int width = board[0].size();
        bool result = false;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == word[0]) {
                    
                    bool res = dfs(word, 0, i, j, board);
                    if (res) {
                        result = res;
                        break;
                    }
                }
                
            }
            if (result) {
                break;
            }
        }
        return result;
    }
};
```