采用递归来解，性能和空间都比较挫，但是写起来较快
执行用时 :60 ms, 在所有 cpp 提交中击败了37.36%的用户
内存消耗 :25.5 MB, 在所有 cpp 提交中击败了32.15%的用户

```
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int totalIm = 0;
        vector<Employee*>::size_type i = 0;
        for (; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                totalIm += employees[i]->importance;
                break;
            }
        }
        if (i == employees.size()) {
            return totalIm;
        }
        vector<int>::size_type j = 0;
        for (; j < employees[i]->subordinates.size(); j++) {
            totalIm += getImportance(employees, employees[i]->subordinates[j]);
        }
        return totalIm;
    }
};
```