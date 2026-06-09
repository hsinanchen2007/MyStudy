### 解题思路
核心要点：对矩阵中每个元素进行DFS深度优先遍历，DFS中对四个方向进行递归调用DFS
注意：
（1）为了不走回头路，DFS递归前将当前指向的矩阵位置处元素保存在tmp中，然后改为空格，待递归完后改回原值；
（2）为了减少多余浪费的计算，可以利用if条件的“短路”原理，只要一个方向递归为true，其他方向就跳过。
执行用时 :24 ms, 在所有 C++ 提交中击败了87.40%的用户
内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool DFS(vector<vector<char>>& board,const string& word,int i,int j,int pos){
        if(pos==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;
        }
        if(word[pos]!=board[i][j]){
            return false;
        }
        char tmp=board[i][j];
        board[i][j]=' ';
        bool success=false;
        if(DFS(board,word,i-1,j,pos+1)||DFS(board,word,i+1,j,pos+1)||DFS(board,word,i,j-1,pos+1)||DFS(board,word,i,j+1,pos+1)){
            success=true;
        }   
        board[i][j]=tmp;
        return success;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!=word[0])continue;
                if(DFS(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};
```