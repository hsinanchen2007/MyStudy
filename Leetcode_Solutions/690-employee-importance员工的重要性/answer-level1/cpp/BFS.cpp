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
        unordered_map<int, Employee*> mp;
        for(int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = employees[i];
        }
        int ans = 0;
        queue<int> q;
        q.push(id);
        
        while(!q.empty()) {
            int t = q.front();
            ans += mp[t]->importance;
            q.pop();
            vector<int> tmp = mp[t]->subordinates;
            for (int i = 0; i < tmp.size(); i++) {
                q.push(tmp[i]);
            }
        }
        return ans;
    }
};
```