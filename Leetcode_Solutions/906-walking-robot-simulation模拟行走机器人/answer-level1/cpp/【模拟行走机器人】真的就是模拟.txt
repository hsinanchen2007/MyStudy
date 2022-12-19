### 思路
1. 将障碍加入 `set` 
2. 定义方向数组 `vector<vector<int>> dd`
3. 根据命令模拟

### 答题
```C++ []
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        set<vector<int>> ob;
        for (auto& p : obstacles)
        {
            ob.insert(p);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob.count(next) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }
```
  
使用 `unordered_map` 提升性能

```C++ []
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int ans = 0;
        unordered_map<int, unordered_set<int>> ob;
        for (auto& p : obstacles)
        {
            ob[p[0]].insert(p[1]);
        }

        vector<vector<int>> dd = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int dir = 0;
        vector<int> pos = { 0,0 };

        for (auto& c : commands)
        {
            dir = (c == -2) ? (dir + 4 - 1) % 4 : dir;
            dir = (c == -1) ? (dir + 1) % 4 : dir;
            for (int i = 0; i < c; i++)
            {
                vector<int> next = { pos[0] + dd[dir][0], pos[1] + dd[dir][1] };
                if (ob[next[0]].count(next[1]) != 0) break;
                pos = next;
                ans = max(ans, pos[0] * pos[0] + pos[1] * pos[1]);
            }
        }

        return ans;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

