### 思路
1. 将员工信息保存
2. bfs （或 dfs）

### 答题
#### bfs
```C++ []
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> mp;
        for (auto p : employees)
        {
            if (p == nullptr) continue;
            mp[p->id] = p;
        }

        int ans = 0;
        queue<int> que;
        que.push(id);

        while (!que.empty())
        {
            ans += mp[que.front()]->importance;
            for (auto n : mp[que.front()]->subordinates)
            {
                que.push(n);
            }
            que.pop();
        }
        return ans;
    }
};
```
#### dfs
```C++ []
class Solution {
public:
    int dfs(unordered_map<int, Employee*>& mp, int id)
    {
        if (mp.count(id) == 0 || mp[id] == nullptr) return 0;
        int ans = mp[id]->importance;
        for (auto n : mp[id]->subordinates)
        {
            ans += dfs(mp, n);
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int, Employee*> mp;
        for (auto p : employees)
        {
            if (p == nullptr) continue;
            mp[p->id] = p;
        }

        return dfs(mp, id);
    }
};
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

