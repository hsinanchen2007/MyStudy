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
    // 非递归（层序遍历）算法 ...
    int getImportance(vector<Employee*> employees, int id) {

        for (auto e : employees) record[e->id] = e;

        queue<Employee*> queue;
        queue.push(record[id]);

        int ans = 0;
        while (!queue.empty()) {
            Employee* e = queue.front(); queue.pop();
            ans += e->importance;

            for (auto id : e->subordinates) {
                queue.push(record[id]);
            }
        }

        return ans;
    }

    int getImportance2(vector<Employee*> employees, int id) {

        for (auto e : employees) record[e->id] = e;

        return getImportance(record[id]);
    }

private:

    unordered_map<int, Employee*> record;

    int getImportance(Employee* e) { // 递归算法
        int importance = e->importance;
        for (auto id : e->subordinates) {
            importance += getImportance(record[id]);
        }

        return importance;
    }
};
```