# 1. 理解
看到这道题首先联想到的是矩阵的最短路径和问题，最短路径可以通过动态规划或分治算法解决，但是这个问题很难找到一个合适动态规划思路，分治算法倒是可以入手。实际上我也是从这个角度思考的：先判断当钱位置是否和字符串的第一个字符相等，相等则递归判断上下左右四个位置是否和子串的第一个字符相等，换个角度思考，这就是深度优先搜索算法。于是开始套用深度优先算法的模板。
# 2. 思路
1. 首先，dfs算法的起始位置有R*C个可能，N和M分别是矩阵的行宽和列宽。
2. 对于每一个起始位置，依次比较上下左右四个位置的值
3. 在每一次比较中，如果某方向上值和字符串的第二个字符相等，则以该方向位置为起始位置，从第二个字符开始为子串递归搜索
4. 递归的终止条件：(1)当前位置和字符串头字符不等,return false; (2)当前位置和字符串头字符相等且字符串长度为1,return true;

**如何判断边界？**
在原矩阵的外围包了一层0，因为字符不可能为0，所以当搜索到此矩阵的最外层时，必然不相等。
**如何记录搜索路径？**
对于已经确定相等的当前位置，先记录当前值，然后将其赋值为0，继续递归搜索。如果递归搜索不到再恢复当前位置的值。
# 3. 代码
```c++ []
class Solution {
public:
    int di[4] = {0,0,1,-1};
    int dj[4] = {1,-1,0,0};
    bool exist(vector<vector<char>>& board, string word) {
        //边界补0
        for(auto line = board.begin(); line!=board.end(); line++){
            line->insert(line->begin(), 0);
            line->push_back(0);
        }
        vector<char> line(board[0].size(), 0);
        board.insert(board.begin(), line);
        board.push_back(line);

        //dfs算法
        for(int i=1; i<board.size()-1; i++){
            for(int j=1; j<board[0].size()-1; j++){
                if(dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j){
        if(word[0] != board[i][j]) return false;
        if(word.size() == 1 && word[0] == board[i][j]) return true;
        int remember = board[i][j];
        board[i][j] = 0;
        for(int d=0; d<4; d++){
            if(board[i+di[d]][j+dj[d]] == word[1]){
                if(dfs(board, word.substr(1), i+di[d], j+dj[d])) return true;
            }
        }
        board[i][j] = remember;
        return false;
    }
};
```
# 4. 总结
这道题一开始在大方向上是对的，只是在实现的细节上，比如递归的终止条件和循环遍历初始位置上都出现了一点小问题，导致代码迟迟不能通过测试。
如果时真实笔试的时候出现了这种情况确实是蛮尴尬的，我想出现这样的原因有两个：
1. 大方向是对的，但是具体的每一行代码还是不清楚，处于想到哪里写到哪里的状态。
2. 不够细致，犯一些低级的错误，比如简单遍历循环的判断条件写错。

**如何在接下来的练习中改善这些问题？**
1. 写代码之前，一定要在草稿纸上写好越详细越好的伪代码
2. 写代码一定要严谨细致，小的错误也很浪费调试时间