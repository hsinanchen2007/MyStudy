## idea 一次遍历
- 列容器和`3x3`容器的生成
-- 把原来数独视为9x9的矩阵，列容器可以认为是行的转置
-- `3x3`宫格在`9x9`矩阵中的位置序号视为行指标（位置序号参阅官方题解），自己内部的排序号视作列指标
- 对生成的容器判断是否有重复，其中`'.'`的重复不予考虑

## 具体实现如下
```c++
class Solution {
/*
** 一次遍历
*/
public:
    bool isrepeat(vector<char>& line) // 判断是否有重复
    {
        char tmp;
        for(int i=0;i<line.size()-1;i++)
        {
            tmp=line[i];
            if(tmp=='.') continue;
            for(int j=i+1;j<line.size();j++)
            if(line[j]==tmp) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<char> dot(9,'.');
        // vector<vector<char>> board_transpose(9,dot); //列容器
        vector<vector<char>> board_transpose=board; //列容器
        vector<vector<char>> board_box=board; //3x3宫格容器
        int box_row_index=0,box_col_index;
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            board_transpose[j][i]=board[i][j]; // 列
            box_row_index=(i / 3) * 3 + j / 3;
            box_col_index=(i % 3) * 3 + j % 3;
            board_box[box_row_index][box_col_index]=board[i][j]; // 3x3宫格
        }

        vector<vector<char>>::iterator it;
        for(it=board.begin();it!=board.end();it++) //行判断
        if(!isrepeat(*it)) return false;

        for(it=board_transpose.begin();it!=board_transpose.end();it++) //列判断
        if(!isrepeat(*it)) return false;

        for(it=board_box.begin();it!=board_box.end();it++) //3x3宫格判断
        if(!isrepeat(*it)) return false;

        return true;
    }
};
```

## 结果
![solution_result.JPG](https://pic.leetcode-cn.com/15444cd54d22d9525958a46094c5f57830323e4b7746b7e551305f0e1eb7794b-solution_result.JPG)
