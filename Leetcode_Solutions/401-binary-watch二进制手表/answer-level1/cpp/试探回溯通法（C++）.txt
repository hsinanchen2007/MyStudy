虽然这道题最好的解法并不是用回溯，而是计算bit位数，但是确实一道非常好的练习试探与回溯的题。

而且本题的框架学会之后，N皇后也是一模一样的。
[N皇后的题解](https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-die-dai-ban-shi-tan-yu-hui-su-c-by-jian/)

here we go：

问题抽象：

1. 建立一个map：vector<int> map{ 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 }; 前4项纪录hours，后6项记录minutes。
2. 简历一个path：stack<int> path；记录每次选择的map中的索引。当path记录的索引数量等于num的时候，就是答案。
3. 建立回溯框架，要搞清楚这几件事：什么时候回溯，什么时候试探，什么时候得到解，什么时候退出遍历。

下面一个一个回答3中的问题：

问题1：什么时候回溯：1. 当试探失败的时候，需要回溯到前一步。 2. 当获得解的时候，需要回溯到前一步继续进行可能的试探。

问题2：什么时候试探：不需要回溯的时候。

问题3：什么时候得到解：试探成功时，并且path中的索引数量等于num。

问题4：什么时候退出遍历：不断的回溯，直到最初的值被弹出，且还是试探失败。

回答完了这些问题，那么可以看下整体框架，如果看懂了整体框架，接下来的就是一些细节了。
需要细细品味这个框架，你会发现和N皇后如出一辙，其实这就是一个回溯的通用框架。根据上述的4个问题来建立起下面的框架。

```
vector<string> readBinaryWatch(int num) {
        vector<string> retval;
        vector<int> map{ 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
        stack<int> path;
        int pos = 0;

        do 
        {
            if (path.size() >= num || pos >= map.size()) //问题1
            {
                // backtracking:
                // 1. find solver
                // 2. pruning
                pos = path.top() + 1;
                path.pop();
            }
            else //问题2
            {
                // probing
                while (pos < map.size() && !available(map, path, pos))
                {
                    pos++;
                }
                if (pos < map.size())
                {
                    path.push(pos);
                    if (path.size() >= num) //问题3
                    {
                        // record solver
                        record(map, path, retval);
                    }
                    pos++;
                }
            }

        } while (!path.empty() || pos < map.size()); //问题4

        return retval;
    }
```
框架中有两个函数available和record，其中available是用来确定试探是否成功，在这里是需要判断hours<12, minutes<60。record则是用来记录解的。

```
bool available(vector<int> &map, stack<int> path, int pos)
    {
        int hours = 0;
        int minutes = 0;
        while (path.size())
        {
            int val = path.top();
            path.pop();
            if (val < 4)
            {
                hours += map[val];
            }
            else
            {
                minutes += map[val];
            }
        }

        if (pos < 4)
        {
            hours += map[pos];
        }
        else
        {
            minutes += map[pos];
        }

        if (hours > 11 || minutes > 59)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
```
```
void record(vector<int> &map, stack<int> path, vector<string> &solver)
    {
        int hours = 0;
        int minutes = 0;
        stringstream time;

        while (path.size())
        {
            int val = path.top();
            path.pop();
            if (val < 4)
            {
                hours += map[val];
            }
            else
            {
                minutes += map[val];
            }
        }

        time << hours << ':';
        if (minutes < 10)
        {
            time << '0' << minutes;
        }
        else
        {
            time << minutes;
        }

        solver.push_back(time.str());
    }
```

整体的代码如下：
```
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> retval;
        vector<int> map{ 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
        stack<int> path;
        int pos = 0;

        if (num <= 0)
        {
            retval.push_back("0:00");

            return retval;
        }

        do 
        {
            if (path.size() >= num || pos >= map.size())
            {
                // backtracking:
                // 1. find solver
                // 2. pruning
                pos = path.top() + 1;
                path.pop();
            }
            else
            {
                // probing
                while (pos < map.size() && !available(map, path, pos))
                {
                    pos++;
                }
                if (pos < map.size())
                {
                    path.push(pos);
                    if (path.size() >= num)
                    {
                        // record solver
                        record(map, path, retval);
                    }
                    pos++;
                }
            }

        } while (!path.empty() || pos < map.size());

        return retval;
    }

    bool available(vector<int> &map, stack<int> path, int pos)
    {
        int hours = 0;
        int minutes = 0;
        while (path.size())
        {
            int val = path.top();
            path.pop();
            if (val < 4)
            {
                hours += map[val];
            }
            else
            {
                minutes += map[val];
            }
        }

        if (pos < 4)
        {
            hours += map[pos];
        }
        else
        {
            minutes += map[pos];
        }

        if (hours > 11 || minutes > 59)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void record(vector<int> &map, stack<int> path, vector<string> &solver)
    {
        int hours = 0;
        int minutes = 0;
        stringstream time;

        while (path.size())
        {
            int val = path.top();
            path.pop();
            if (val < 4)
            {
                hours += map[val];
            }
            else
            {
                minutes += map[val];
            }
        }

        time << hours << ':';
        if (minutes < 10)
        {
            time << '0' << minutes;
        }
        else
        {
            time << minutes;
        }

        solver.push_back(time.str());
    }
};
```
