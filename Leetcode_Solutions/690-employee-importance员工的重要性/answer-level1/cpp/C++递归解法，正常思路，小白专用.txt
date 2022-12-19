### 解题思路
感觉做不出来，我特喵就试了一下递归，竟然就通过了，像梦一样。

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
    int impotence;
    void dfFun(vector<Employee*> employees, int id)
    {
        for (auto i:employees) {
            if (i->id == id) {
                impotence += i->importance;
                if (i->subordinates.empty()) {
                    return;
                } else {
                    for (int j =0 ; j < i->subordinates.size();j++) {
                        dfFun(employees, i->subordinates[j]);
                    }
                }
            }
        }
        
        return;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0;
        for (auto i:employees){
            if (i->id == id) {
                dfFun(employees, id);
            }
        }
        ret = impotence;

        return ret;
    }
};
```