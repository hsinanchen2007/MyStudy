```c++
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
    void see(vector<Employee*> &employees,int & importance,stack<int>&idx,int id){
        auto start=employees.begin();
        while(start!=employees.end()){
                    if ((*start)->id==id){
                        for(auto i:(*start)->subordinates)
                            idx.push(i);
                        importance+=(*start)->importance;
                        employees.erase(start);
                        break;
                    }
                    start++;
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        stack<int>idx;
        int importance=0;
        see(employees,importance,idx,id);
        while (!idx.empty() && !employees.empty()){
            id=idx.top();
            idx.pop();
           see(employees,importance,idx,id);
        }
        return importance;
    }
};
```
