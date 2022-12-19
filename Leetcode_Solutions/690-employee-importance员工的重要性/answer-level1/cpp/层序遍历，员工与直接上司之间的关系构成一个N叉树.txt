### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty()) {
            return 0;
        }

        map<int, int> m;
        Employee* target = nullptr;
        for (int i = 0; i < employees.size(); ++i) {
            m[employees[i]->id] = i;
        }
        
        if (m.count(id) == 0) {
            return 0;
        }

        // 进行层序遍历
        queue<int> q;
        int res = 0;
        q.push(id);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto it = m.find(q.front());
                q.pop();
                if (it == m.end()) {
                    continue;
                }
                Employee* emp = employees[it->second];
                res += emp->importance;
                for (auto n : emp->subordinates) {
                    q.push(n);
                }
            }
        }
        return res;
    }
};
```