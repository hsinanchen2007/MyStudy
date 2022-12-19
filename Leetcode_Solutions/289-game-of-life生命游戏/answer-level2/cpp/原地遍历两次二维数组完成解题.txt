### 解题思路
此处撰写解题思路
![QQ截图20200402192005.png](https://pic.leetcode-cn.com/065400a1377338a5a0123d4a5766e86fc82afd1a81dbebc54b0411544d07218f-QQ%E6%88%AA%E5%9B%BE20200402192005.png)
第一遍遍历：
将活变死的细胞标记为3，死变活的细胞标记为2。
检测周围细胞时1与3同样作为活细胞对待。
第二遍遍历：
将3标记为0，将2标记为1。
~~因为死的细胞真的死了，活的细胞也真的活了~~
### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                if(i-1>=0&&j-1>=0) if(board[i-1][j-1]==1||board[i-1][j-1]==3) count++;
                if(i-1>=0) if(board[i-1][j]==1||board[i-1][j]==3) count++;
                if(i-1>=0&&j+1<n) if(board[i-1][j+1]==1||board[i-1][j+1]==3) count++;
                if(j+1<n) if(board[i][j+1]==1||board[i][j+1]==3) count++;
                if(j+1<n&&i+1<m) if(board[i+1][j+1]==1||board[i+1][j+1]==3) count++;
                if(i+1<m)  if(board[i+1][j]==1||board[i+1][j]==3) count++;
                if(i+1<m&&j-1>=0)  if(board[i+1][j-1]==1||board[i+1][j-1]==3) count++;
                if(j-1>=0)  if(board[i][j-1]==1||board[i][j-1]==3) count++;
                //原死细胞
                if(board[i][j]==0) if(count==3) board[i][j]=2;
                //原活细胞
                if(board[i][j]==1) if(count<2||count>3) board[i][j]=3;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=1;
                if(board[i][j]==3) board[i][j]=0;
            }
        }
    }
};
```