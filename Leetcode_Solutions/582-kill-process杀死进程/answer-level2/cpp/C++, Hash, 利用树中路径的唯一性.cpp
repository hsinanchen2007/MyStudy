利用树的性质：树内的任意两个顶点能被唯一路径所连通。
我们只需遍历所有的PID，找到其到PID0进程的路径。如果被kill的进程是该PID的祖先，那么被kill的进程一定在该路径上。因此，如果某一PID到PID0的路径上中包含被kill的进程，则认为该进程是被kill进程的后代，因此也需要被kill。

```cpp
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        auto res = vector<int>{};
        unordered_map<int, int> pid_map{};
        for(size_t i = 0; i < pid.size(); ++i)
        {
            pid_map[pid[i]] = ppid[i];
        }
        for(auto p : pid)
        {
            auto tmp = p;
            while(tmp)
            {
                if(tmp == kill) 
                {
                    res.push_back(p);
                    break;
                }
                tmp = pid_map[tmp];
            }
        }
        return res;
    }
};
```
