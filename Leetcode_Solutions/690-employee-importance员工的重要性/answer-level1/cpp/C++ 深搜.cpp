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
    unordered_map<int, int> map;
    int sum;

    void dfs(vector<Employee*> employees, int idx) {
        sum += employees[idx]->importance;
        int size = employees[idx]->subordinates.size();
        if (size == 0) {
            return;
        }

        for (int i = 0; i < size; i++) {
            dfs(employees, map[employees[idx]->subordinates[i]]);
        }
    }

public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        int res = 0;
        for (int i = 0; i < size; i++) {
            map[employees[i]->id] = i;
        }
        dfs(employees, map[id]);

        return sum;
    }
};
```