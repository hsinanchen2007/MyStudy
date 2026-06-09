[401. Binary Watch的题解与此一样](https://leetcode-cn.com/problems/binary-watch/solution/di-gui-hui-su-tong-fa-c-by-jiangtianyu007/)

写回溯的时候需要回到这四个问题：

问题1：什么时候回溯：1. 当试探失败的时候，需要回溯到前一步。 2. 当获得解的时候，需要回溯到前一步继续进行可能的试探。

问题2：什么时候试探：不需要回溯的时候。

问题3：什么时候得到解：试探成功时，并且path中的数量等于n。

问题4：什么时候退出遍历：不断的回溯，直到最初的值被弹出，且还是试探失败。

```
#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Queen
{
public:
    int x;
    int y;

    Queen()
    {
        x = 0;
        y = 0;
    }

    Queen(int xx, int yy)
    {
        x = xx;
        y = yy;
    }

    bool operator== (Queen &q)
    {
        return ((x == q.x) || (y == q.y) || (x + q.y) == (y + q.x) || (x - q.x) == (q.y - y));
    }

    bool operator!= (Queen &q)
    {
        return !(*this == q);
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        Queen q(0, 0);
        stack<Queen> path;
        vector<vector<string>> retval;
        do 
        {
            if (path.size() >= n || q.y >= n)
            {
                // backtracking
                q = path.top();
                path.pop();
                q.y++;
            }
            else
            {
                // probing
                while (q.y < n && !available(path, q))
                {
                    q.y++;
                }
                if (q.y < n)
                {
                    path.push(q);
                    if (path.size() >= n)
                    {
                        // find solver
                        record(path, retval, n);
                    }
                    q.x++;
                    q.y = 0;
                }
            }
        } while (!(path.empty() && q.y >= n));

        return retval;
    }

    bool available(stack<Queen> path, Queen &q)
    {
        Queen val;
        while (!path.empty())
        {
            val = path.top();
            path.pop();
            if (val == q)
            {
                return false;
            }
        }

        return true;
    }

    void record(stack<Queen> path, vector<vector<string>> &solvers, int n)
    {
        Queen val;
        int i;
        vector<string> solver;
        while (!path.empty())
        {
            val = path.top();
            path.pop();
            string s;
            for (i = 0; i < n; i++)
            {
                if (i != val.y)
                {
                    s.push_back('.');
                }
                else
                {
                    s.push_back('Q');
                }
            }
            solver.push_back(s);
        }
        solvers.push_back(solver);
    }
};
```

