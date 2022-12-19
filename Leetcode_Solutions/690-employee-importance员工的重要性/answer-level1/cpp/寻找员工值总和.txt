### 解题思路
题目要求输出一个员工和他的属下的价值总和。
题目的输入数据比较有意思，类似一张广义表。获取和的话，可以采用先序遍历，应当不用担心一个员工有两个领导这种情况。

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
        int ans=0;
        result(employees,id,ans);
        return ans;
    }
    void result(vector<Employee*> employees,int id,int &ans){
        int pos = find(employees,id);
        if(pos==-1) return;
        if(employees[pos]->subordinates.empty()){
            ans+=employees[pos]->importance;
            return;
        }
        ans+=employees[pos]->importance;
        for(int i=0;i<employees[pos]->subordinates.size();i++){
            result(employees,employees[pos]->subordinates[i],ans);
        }
        return;

    }
    int find(vector<Employee*> employees,int id){
        int len=employees.size();
        for(int i=0;i<len;i++){
            if(employees[i]->id==id){
                return i;
            }
        }
        return -1;
    }
};
```