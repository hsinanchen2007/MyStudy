### 解题思路

- 记录数独方阵中已有数字的信息——需要三个二维数组 row[ ][ ] 、 col[ ][ ] 、 rec[ ][ ]
- row[ ][ ] 记录第 i 行出现过的数字
- col[ ][ ] 记录第 j 列出现过的数字
- rec[ ][ ] 记录第 t 个 3*3 宫中出现过的数字
- 深度优先遍历：先行后列，即填完一行中的所有列再开始填写下一行
- 依次在需要填数字的空格上填写符合条件的数字
- 条件是满足 `if(!row[u][k] && !col[j][k] && !rec[t][k])`
- 如果该位置没有符合条件的数就回溯至上一个位置，在上一个位置重新选择一个符合条件的数填写
- 从board[0][0]开始枚举数独的所有可能情况，直到枚举到board[8][8] 说明已找到数独的解 返回

**数独：**
![37.JPG](https://pic.leetcode-cn.com/a60493fb3d2661a000dfd52ebc8de154224bbbada6f80097c7cabae4ef2f8632-37.JPG)

**数组 row[ ] :**
![image.png](https://pic.leetcode-cn.com/a53f522b436e062b14bb0f82dea72a945d7f35f2161f50e8fe7ca3813ef6068c-image.png)

**数组 col[ ] :**
![image.png](https://pic.leetcode-cn.com/ee8598d369c295be0acc30ca6340fc08e1b62c05269801f001512d4a54568fe0-image.png)

**数组 rec[ ] :**
![image.png](https://pic.leetcode-cn.com/d718d6c4d355b5bbcd4c0d38c1ee8d8aae149a3a20715726fcf2a1608c4d97f8-image.png)

**函数 map(int i,int j) : 用于将 board[i][j] 与相应的 3*3 正方形对应**
![image.png](https://pic.leetcode-cn.com/a47ba0159ff5d961205c62f62a3ea2acef05ad9169c2d85d7538896b643f1662-image.png)


### 代码

```cpp
class Solution {
public:
    int col[9][9]={0},row[9][9]={0},rec[9][9]={0};
    
    //3*3宫的对应函数
    int map(int i,int j){
        if(0 <= i && i <= 2){
            if(0 <= j && j <= 2) return 0;
            else if(3 <= j && j <= 5) return 1;
            else return 2;
        }
        else if(3 <= i && i <= 5){
            if(0 <= j && j <= 2) return 3;
            else if(3 <= j && j <= 5) return 4;
            else return 5;
        }
        else{
            if(0 <= j && j <= 2) return 6;
            else if(3 <= j && j <= 5) return 7;
            else return 8;
        }
    }
  
    bool dfs(vector<vector<char>>& board,int u,int j){
        if(u == 8 && j ==9) return true;  //已遍历完所有，找到解
        if(j == 9 && u < 8){    //一行遍历完成，开始遍历下一行
            u ++;
            j = 0;
        }
        if(board[u][j] != '.')   //该位置已有值，向下遍历
           return dfs(board,u,j + 1);
        int t=map(u,j);          // board[u][j] 对应第 t 个3*3方阵
        for(int k = 0;k < 9;k ++)  // 共有值1 - 9可选，条件成立，填入 k + 1
            if(!row[u][k] && !col[j][k] && !rec[t][k]){
                row[u][k] = col[j][k] = rec[t][k] = true;  // 修改记录数组
                board[u][j] = k + 1 + '0';
                if(!dfs(board,u,j + 1)){     //进入下一次遍历不成立则回溯
                    row[u][k] = col[j][k] = rec[t][k] = false;
                    board[u][j] = '.';
                }  
                else return true;    
            }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //先遍历一遍数独方阵，记录已有数字的位置信息
        for(int i = 0;i < 9;i ++)
           for(int j = 0;j < 9;j ++)
               if(board[i][j] != '.'){
                   row[i][board[i][j]-1-'0'] = true;
                   col[j][board[i][j]-1-'0'] = true;
                   int t = map(i,j);
                   rec[t][board[i][j]-1-'0'] = true;
               }
        dfs(board,0,0); //从board[0][0]开始枚举数独的所有可能情况
    }
};
```