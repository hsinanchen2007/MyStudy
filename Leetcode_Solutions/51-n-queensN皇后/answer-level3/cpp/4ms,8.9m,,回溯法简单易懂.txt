![题解.png](https://pic.leetcode-cn.com/aea5c3b22ddce92bec8845c829e488d90ecb37e2824b4b888fa0c820ddd4b139-%E9%A2%98%E8%A7%A3.png)
### n皇后问题的实质：
1.一行一个皇后
2.每个皇后的左上方向没有其他皇后，每个皇后的上方没有其他皇后，每个皇后的右上方向没有皇后
### 回溯法的实质：
1.每一行从第一格开始试，放得下就继续往下一行，放不下就试下一格，一行都没得放就改上一行的位置
其实就是从第一行开始暴力试，每个格子都试过就好了。
### 所以我们的代码策略：
1.第一行每一格都要试
2.第一行的基础上每一格试一遍，符合要求进下一行，不符合不管
3.第二行的基础上每一格试一遍，符合要求进下一行，不符合不管
4.类同上
。。。。
n.第n格满足了，存进结果里。
直接看代码：
```
class Solution {
    vector<vector<string>> res;//存结果
    vector<string> tmp;//存棋盘
public:
    vector<vector<string>> solveNQueens(int n) {
        string line(n,'.');//既然一行一行试，那就一行一行存
        solveNQueens(line, 0, n);//从第0行开始
        return res;
    }

private:
    //试某一行
    void solveNQueens(string& line, int row, int n)
    {
        if(tmp.size() == n)//棋盘绘制够n行存进结果，不用继续试了
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; ++i)//一格一格，每格都要试
        {
            if(checkAll(row, i, n))     //符合条件了
            {
                line[i] = 'Q';          //就把当前试的这一格放皇后
                tmp.push_back(line);    //然后把这一行绘制进棋盘
                line[i] = '.';          //棋盘的下一行应该是没有皇后的
                solveNQueens(line, row + 1, n);//去试下一行
                tmp.pop_back();         //接下来要去试下一格，刚才绘制进去的那一行删掉
            }
        }
    }

    //暴力检查条件
    bool checkAll(int row, int col, int n)
    {
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i,--j)//左上方
        {
            if(tmp[i][j] == 'Q')
                return false;
        }
        for(int i = row - 1; i >= 0; --i)//正上方
        {
            if(tmp[i][col] == 'Q')
                return false;
        }
        for(int i = row -1, j = col + 1; i >= 0 && j < n; --i, ++j)//右上方
        {
            if(tmp[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
```
结束，我jio得已经很清楚了