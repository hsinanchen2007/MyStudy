### 解题思路

这道题就是先定义三个数组来保存状态，然后遍历数组。对每个状态进行判断调整。
重要的是用order = i/3*3+j/3;来求出当前数组属于哪个格子。


### 代码

```cpp
class Solution {
public:
    // 执行用时 :16 ms, 在所有 C++ 提交中击败了69.94% 的用户
    // 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> temp(9, false);
        vector<vector<bool> > rows(9,temp);//初始化一个二维数组用来判断某一排的某个数是否重复
        vector<vector<bool> > clos(9,temp);//初始化一个二维数组用来判断某一列的某个数是否重复
        vector<vector<bool> > blocks(9,temp);//初始化一个二维数组用来判断某一个格子中的某个数是否重复
        for(int i = 0; i<9;++i){
            for(int j = 0;j<9;++j){
                if(board[i][j]!='.'){
                    int order = i/3*3+j/3;//计算出这个数处于第几个格子，i/3*3
                    if(rows[i][board[i][j]-'1']||clos[board[i][j]-'1'][j]||blocks[order][board[i][j]-'1']) return false;
                    else{
                        rows[i][board[i][j]-'1'] = true;
                        clos[board[i][j]-'1'][j] = true;
                        blocks[order][board[i][j]-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
};
```