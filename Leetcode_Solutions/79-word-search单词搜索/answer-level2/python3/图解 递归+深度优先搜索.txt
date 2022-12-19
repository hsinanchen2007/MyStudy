### 解题思路：深度优先搜索 DFS

我们可以将矩阵看作一个无向图。对于无向图，我们可以采用深度优先搜索和广度优先搜索两种办法进行遍历。

![幻灯片11.JPG](https://pic.leetcode-cn.com/3aa75e29ee72da14df37229c76f21a2308a299fbb4800656f8f9b39f50d14d90-%E5%B9%BB%E7%81%AF%E7%89%8711.JPG)

因此对于 `word = ABCCEE`，我们可以先采用暴力搜索的办法找到目标字符串 `word` 中的第一个字符 `A`,找到之后按照深度优先搜索的顺序寻找是否有和 `word` 匹配的字符串，如果找到直接返回 `True`；如果没有，我们继续寻找下一个 `A`...

对于一轮深度搜索过程中，为了避免重复我们需要将搜索过的字符置为 `0`。

![12.gif](https://pic.leetcode-cn.com/92e383cc1ca508f71d8eccd092c0333977651d7ce9de6672383981a2d78fb0c5-12.gif)



### 代码

```python []
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # 使用深度优先搜索
        if not board:   # 边界条件
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False

    def dfs(self, board, i, j, word):
        if len(word) == 0: # 如果单词已经检查完毕
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j]:  # 如果路径出界或者矩阵中的值不是word的首字母，返回False
            return False
        tmp = board[i][j]  # 如果找到了第一个字母，检查剩余的部分
        board[i][j] = '0'
        res = self.dfs(board,i+1,j,word[1:]) or self.dfs(board,i-1,j,word[1:]) or self.dfs(board,i,j+1,word[1:]) or self.dfs(board, i, j-1, word[1:]) # 上下左右四个方向搜索

        board[i][j] = tmp  # 标记过的点恢复原状，以便进行下一次搜索
        return res
```
```cpp []
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for (int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if (dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i,int j,int length){
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||length>=word.size()||word[length]!=board[i][j]){
            return false;
        }
        if(length==word.size()-1&&word[length]==board[i][j]){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='0';
        bool flag=dfs(board,word,i,j+1,length+1)||dfs(board,word,i,j-1,length+1)||dfs(board,word,i+1,j,length+1)||dfs(board,word,i-1,j,length+1);
        board[i][j]=temp;  // 标记过的点恢复原状，以便进行下一次搜索
        return flag;
    }
};
```


### 复杂度分析

非常感谢 [@ZacBi](/u/zacbi/) 对时间复杂度和空间复杂度提出的宝贵意见~

**1. 时间复杂度：${\mathcal{O}}((M\times N)^2)$。**

根据 [力扣相关介绍](https://leetcode-cn.com/explore/orignial/card/recursion-i/259/complexity-analysis/1223/)：

>给出一个递归算法，其时间复杂度 ${\mathcal{O}(T)}$ 通常是递归调用的数量（记作 ${R}$） 和计算的时间复杂度的乘积（表示为 ${\mathcal{O}(s)}$）的乘积：${\mathcal{O}(T) = R * \mathcal{O}(s)}$ 

$M$，$N$ 为矩阵的行数和列数。每个递归函数需要调用 `word.size()` 次。最坏情况下，`word` 为蛇形排列，长度为矩阵中的所有元素的数量，故每个递归函数调用次数为 $O(M\times N)$，且一次调用了四个递归函数，递归调用的总次数为 $\mathcal{O}(4\times M\times N )$，在递归函数中我们只进行了 `board[i][j] = tmp`，复杂度为 $\mathcal{O}(1)$，故递归的总时间复杂度为 ${\mathcal{O}(T) = \mathcal{O}(4\times M\times N) * \mathcal{O}(1)}={\mathcal{O}}(M\times N)$ 

在主函数中的时间复杂度为 $\mathcal{O}(M\times N)，$ 故总的时间复杂度为 $O((M\times N)^2)$。

**2. 空间复杂度：${\mathcal{O}}(M\times N)$。**



对于每个递归调用 `self.dfs(board,i+1,j,word[1:])`，假设它可能需要一个最大为某一常量值的空间,并且需要递归调用 `word.size()` 次，而 `word` 最长为 $(M\times N)$，所以对于每一个递归函数所需的空间复杂度为 ${\mathcal{O}}(M\times N)$，由于我们求 `res` 时需要一次执行四个递归函数，复杂度变成 ${\mathcal{O}}(4\times (M\times N))$，故最后的空间复杂度为 ${\mathcal{O}}(M\times N)$。





如有问题，欢迎讨论~

PS：想要一起努力的童鞋们可以关注我创办的公众号：腐烂的橘子，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋