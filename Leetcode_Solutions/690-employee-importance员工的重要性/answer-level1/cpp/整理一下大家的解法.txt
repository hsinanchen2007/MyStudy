### 解题思路
参考了各路大佬的代码：1.递归，调用自身获取直系下属和其他下属的重要度；
2.把数组转到哈希表，利用哈希表进行查找，并将每一个相关下属的信息存入栈中，每计数一次重要度就pop一次

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
        //递归
        // for(Employee* e:employees){
        //     if(e->id==id){
        //         if(e->subordinates.size()==0) return e->importance;
        //         for(int subid:e->subordinates){
        //             e->importance+=getImportance(employees,subid);
        //         }
        //         return e->importance;
        //     }
        // }
        // return 0;

        //哈希表加栈
        unordered_map<int,Employee*>mymap;
        stack<Employee*>stc;
        int sum=0;
        for(int i=0;i<employees.size();i++){
            mymap[employees[i]->id]=employees[i];//数组转为map便于查找
        }
        if(!mymap.count(id)) return 0;
        stc.push(mymap[id]);//将id放入栈中
        while(!stc.empty()){
            Employee* temp=stc.top();
            stc.pop();
            sum+=temp->importance;
            for(int i=0;i<temp->subordinates.size();i++){
                stc.push(mymap[temp->subordinates[i]]);
            }
        }
        return sum;
    }
};
```