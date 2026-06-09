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
        int importance = 0;
        int i =0;
        /*先获取该员工的id和下属信息*/
        for(i = 0; i<employees.size(); i++){
            if(employees[i]->id == id){
                importance = employees[i]->importance;
                break;
            }
        }

        /*遍历下属信息表递归调用*/
        for(int j = 0; j < employees[i]->subordinates.size(); j++ ) {
            importance = importance + getImportance(employees,employees[i]->subordinates[j]);
        }
        return importance;
    }
    
};
```