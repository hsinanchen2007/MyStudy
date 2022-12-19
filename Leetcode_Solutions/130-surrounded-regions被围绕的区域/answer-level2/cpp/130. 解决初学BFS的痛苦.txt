![image.png](https://pic.leetcode-cn.com/dab161bade58a7e74cd324156702f6270c596a399c27278df0dccbff13808d87-image.png)

### 前言
连着做了好几道可以使用BFS的题目，基本上效率都比较低，代码量也比较高。
但是不失为一种可行的方法，在此记录一下。

初学BFS的难点在于如何确定节点结构。**道理我都懂，二叉树的层序遍历大家都会(不会的话去做一下就好了，有两种模式)，问题是你这种搞个图的题目，我不知道节点是啥啊，我没有left，也没有right啊，甚至没有TreeNode啊！**

### 关键问题1. 队列节点是什么？
这是个抽象的问题，在我看来，本题的节点就是**一组坐标**（有时候节点是一个数字）。我习惯用vector<int> 来表示，里面存两个数。也就是说队列中的一个node，就是一个vector，这个vector有两个元素，分别是横纵坐标。

### 关键问题2. 本题的逻辑
1. 首先绕着外围转一圈，把是O的位置，都构造一个节点入队。
2. 队中的这些node，都是传染源，一个传染俩（最多是3），我让他们尽可能地去传染周边的‘O’，被传染的‘O’就改成‘a’，当然他自己也改成‘a’。
3. 尽可能地传染完了之后，现在的boad中可能有3种字符：X，O，a。 剩下的O就一定是内部的了，因为我洪泛式地去感染，都没感染到他，那他肯定是被隔离了。

这里面还有一些细节，不再这赘述了，懂的自然懂，不懂的说了更懵逼。


### 代码

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()<3 || board[0].size()<3) return ;
        queue<vector<int>> que;
        int last_row = board.size()-1;
        int last_col = board[0].size()-1;
        for(int i=0; i<board[0].size(); i++){// 第0行和最后一行
            if(board[0][i] == 'O') que.push(vector<int>{0,i});
            if(board[last_row][i] == 'O') que.push(vector<int>{last_row,i});
        }
        for(int i=1; i<board.size()-1; i++){// 第0列和最后一列
            if(board[i][0] == 'O') que.push(vector<int>{i,0});
            if(board[i][last_col] == 'O') que.push(vector<int>{i,last_col});
        }
        if(que.size() == 0){ // 如果周围没有0，那全部置为X就可以了
            for(int i=0; i<board.size(); i++){
                for(int j=0; j<board[0].size(); j++){
                    if(board[i][j] == 'O') board[i][j]='X';
                }
            }
            return ;
        }

        while(que.size()){ // 最普通的BFS
            vector<int> node = que.front();
            que.pop();
            int x = node[0];
            int y = node[1];

            board[x][y] = 'a';
            if(x-1>=0 && board[x-1][y]=='O'){
                board[x-1][y] = 'a';
                que.push(vector<int>{x-1,y});
            }
            if(x+1<board.size() && board[x+1][y]=='O'){
                board[x+1][y] = 'a';
                que.push(vector<int>{x+1,y});
            }
            if(y-1>=0 && board[x][y-1]=='O'){
                board[x][y-1] = 'a';
                que.push(vector<int>{x,y-1});
            }
            if(y+1<board[0].size() && board[x][y+1]=='O'){
                board[x][y+1] = 'a';
                que.push(vector<int>{x,y+1});
            }
        }
        for(int i=0; i<board.size(); i++){ // 检查X/O/a
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'a'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};
```
有点用的话求赞啊。