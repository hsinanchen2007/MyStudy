![image.png](https://pic.leetcode-cn.com/af6b7e14cc781e9ca4fb8c555c07705e0c8e0c5b7ee8c2bf7f0df7799f400420-image.png)

### 解题思路
注意使用引用的方式传递参数。
同时在递归进行下一步尝试前，就先判断是否已经走到回溯的终点，而不是把判断走到终点的操作丢到下一步回溯的开头，这样可以节省函数压栈的开销，减少递归层次。

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
            //从所有等于word的首字母的地方开始进行深度优先搜索。
    int rowCount = board.size();
    if (rowCount) {
        int columnCount = board[0].size();
        if (columnCount) {
            char firstChar = word[0];
            int wordLength = word.length();
            for (int rowIndex = 0; rowIndex != rowCount; rowIndex++) {
                for (int columnIndex = 0; columnIndex != columnCount; columnIndex++) {
                    //从与字符串首字母相同的位置开始进行搜索
                    if (board[rowIndex][columnIndex] == firstChar) {
                        if (exist(board, word, wordLength, rowCount, columnCount, rowIndex, columnIndex, 0))                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;

    }

    bool exist(vector<vector<char>>& board, string &word,int wordLength,int rowCount,int columnCount,int rowIndex,int columnIndex,int currentWordIndex)
{
    //已经达到目标长度
    if (wordLength == currentWordIndex + 1) {
        return true;
    } else {
        //进行下一个阶段的尝试。
        //将当前字符标记为已经被占用
        char temp = board[rowIndex][columnIndex];
        board[rowIndex][columnIndex] = 0;
        //上
        if (rowIndex >= 1 && board[rowIndex - 1][columnIndex] == word[currentWordIndex + 1]) {
            if (currentWordIndex + 2 == wordLength) {
                return true;
            }
            if (exist(board, word, wordLength,rowCount,columnCount, rowIndex - 1, columnIndex, currentWordIndex + 1)) {
                return true;
            }
        }
        //下
        if (rowIndex + 1 < rowCount && board[rowIndex + 1][columnIndex] == word[currentWordIndex + 1]) {
            if (currentWordIndex + 2 == wordLength) {
                return true;
            }   
            if (exist(board, word,wordLength, rowCount,columnCount, rowIndex + 1, columnIndex, currentWordIndex + 1)) {
                return true;
            }
        }
        //左
        if (columnIndex >= 1 && board[rowIndex][columnIndex - 1] == word[currentWordIndex + 1]) {
            if (currentWordIndex + 2 == wordLength) {
                return true;
            }
            
            if (exist(board, word,wordLength, rowCount,columnCount, rowIndex, columnIndex - 1, currentWordIndex + 1)) {
                return true;
            }
        }
        //右
        if (columnIndex + 1 < columnCount  && board[rowIndex][columnIndex + 1] == word[currentWordIndex + 1]) {
            if (currentWordIndex + 2 == wordLength) {
                return true;
            }
            if (exist(board, word,wordLength, rowCount,columnCount, rowIndex, columnIndex + 1, currentWordIndex + 1)) {
                return true;
            }
        }
        //取消当前字母被占用
        board[rowIndex][columnIndex] = temp;
    }
    return false;
}

};
```