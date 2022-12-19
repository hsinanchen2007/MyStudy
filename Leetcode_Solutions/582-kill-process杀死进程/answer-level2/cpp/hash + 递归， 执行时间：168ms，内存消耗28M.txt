### 解题思路
1、将父进程ppid转化unordered_multimap，pid作为key，位置下标作为value，这样可以实现ppid的快速查找，以及对应子进程pid；
2、然后对每个子进程pid进行递归删除。

### 代码

```cpp
class Solution {
private:
    vector<int> result;
    std::unordered_multimap <int, int> ppidMultimap;

public:
    void myKillProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        result.insert(result.end(), kill);

        auto range = ppidMultimap.equal_range(kill);
        for (auto it = range.first; it != range.second; ++it) {
            myKillProcess(pid, ppid, pid[it->second]);
        }

        return;
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        result.clear();
        ppidMultimap.clear();
    
        if (kill == 0) {
            result = pid;
            result.insert(result.end(), kill);
            return result;
        }
    
        int sequence = 0;
        for (auto it = ppid.begin(); it != ppid.end(); ++it) {
            ppidMultimap.insert(std::make_pair(*(it), sequence++));
        }
    
        myKillProcess(pid, ppid, kill);
        return result;
    }
};