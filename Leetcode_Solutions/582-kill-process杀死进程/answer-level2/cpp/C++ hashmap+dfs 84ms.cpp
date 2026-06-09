![image.png](https://pic.leetcode-cn.com/426e77d594d6c7cb7f7619edf8971d3733eb5912935678ce6626d411156469ce-image.png)

hashmap维护父子关系，然后dfs，完事了

```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
        for (int i = 0; i < pid.size(); i++) {
            relations_[ppid[i]].emplace_back(pid[i]);
        }
        pid.clear();
        pid.reserve(ppid.size());
        getSon(kill, pid);
        return pid;
    }
private:
    void getSon(int parent, vector<int>& result)
    {
        result.emplace_back(parent);
        auto iter = relations_.find(parent);
        if (iter != relations_.end()) {
            for (auto pid : iter->second) {
                getSon(pid, result);
            }
        }
    }

    unordered_map<int, list<int>> relations_;
};
```
