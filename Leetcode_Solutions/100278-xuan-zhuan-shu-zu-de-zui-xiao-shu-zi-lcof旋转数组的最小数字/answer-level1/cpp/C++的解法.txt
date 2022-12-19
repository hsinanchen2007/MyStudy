### 解题思路
利用set容器的自动排序，耗时较长

### 代码

```cpp
#include<set>
class Solution {
public:
    int minArray(vector<int>& numbers) {
        multiset<int> result;
        for(vector<int>::iterator it=numbers.begin(); it!=numbers.end(); it++){
            int middle = *it;
            result.insert(middle);
        }
        
        return *result.begin();
    }
};
```