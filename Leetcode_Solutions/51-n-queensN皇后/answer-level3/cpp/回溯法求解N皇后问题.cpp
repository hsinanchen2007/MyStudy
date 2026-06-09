### 解题思路
该问题求解N皇后问题的所有可行解，容易联想到使用回溯法求解解空间树中的可行解。
使用数组q来存放棋盘每一行中棋子的列值。
在回溯法求解解空间树的过程中，当行计数值到达棋盘最后一行时，即找到一个可行解，输出结果。
当q数组的列值超过棋盘的大小时，即不满足解，将行计数值减小进行回溯。
当还未到达棋盘最后一行时，行计数值增加同时q数组置位。
通过编写place方法来判断当前列值是否满足条件，若不满足则列值增加。

### 代码

```cpp
class Solution {
public:
    int q[100]={0};

    bool place(int i)
    {
        int j=1;
        if(i==1)
            return true;
        while(j<i)
        {
            if(abs(q[j]-q[i])==abs(j-i)||q[j]==q[i])
                return false;
            j++;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        int i=1;
        q[i]=0;
        while(i>=1)
        {
            q[i]++;
            while(q[i]<=n&&!place(i))
                q[i]++;

            if(q[i]<=n)
            {
                if(i==n)
                {
                    vector<string> temp;
                    for(int a=1;a<=n;a++)
                    {
                        string s(n,'.');
                        s[q[a]-1]='Q';
                        temp.push_back(s);
                    }
                    res.push_back(temp);
                }
                else
                {
                    i++;
                    q[i]=0;
                }
            }
            else
            {
                i--;
            }
        }
        return res;
    }
};
```