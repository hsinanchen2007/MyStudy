```
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
      int sum = 0;
      stack<int> idPool;
      idPool.push(id);
      for(; !idPool.empty();) {
        int idCur = idPool.top();
        idPool.pop();
        for(int i = 0; i < employees.size(); i++) {
            if(employees[i]->id == idCur) {
                sum += employees[i]->importance;
                vector<int> temp = employees[i]->subordinates;
                for(auto ii : temp) {
                    idPool.push(ii);
                }
                break;
            }
        }
      }
      return sum;
    }
};
```