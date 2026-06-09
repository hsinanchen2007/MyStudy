### 解题思路
执行用时 :32 ms, 在所有 C++ 提交中击败了94.11% 的用户
内存消耗 :25.7 MB, 在所有 C++ 提交中击败了15.54%的用户

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
    	if(!employees.size()) return 0;

    	int target_em_id = 0;
//    	cout << "Now employees.size() = " << employees.size() << endl;
    	for(size_t i=0; i<employees.size(); ++i){
    		if(employees[i]->id == id){
    			target_em_id = i;
    			break;
    		}
    	}
//    	cout << "target_em_id = " << target_em_id << endl;

    	size_t sub_ordinates_size = employees[target_em_id]->subordinates.size();

    	if(!sub_ordinates_size) {
//    		cout << "sub.size() == 0 ---> return " << employees[target_em_id]->importance << endl;
    		return employees[target_em_id]->importance;
    	}

    	int importance = 0;
    	importance += employees[target_em_id]->importance;
//    	cout << "importance = " << importance << endl;

    	int sub_ordinates_id = 0;
    	while(sub_ordinates_id < sub_ordinates_size){
    		importance += getImportance(employees, employees[target_em_id]->subordinates[sub_ordinates_id]);
    		sub_ordinates_id++;
    	}

    	return importance;
    }
};
```