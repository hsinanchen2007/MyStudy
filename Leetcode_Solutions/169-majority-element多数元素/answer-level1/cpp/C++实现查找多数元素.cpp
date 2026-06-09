### 解题思路
其实最直接的思路就是统计每个数的次数，并且如果有数的统计次数大于n/2，就输出该数，暴力解法遍历，但时间复杂度较高，尝试用map和iterator解决问题，因为对迭代器的理解不是很到位，所以可能还是比较复杂。

### 代码

```cpp
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> vec_nums;
        for(int i=0;i<nums.size();i++){
            map<int,int>::iterator iter;
            iter=vec_nums.find(nums[i]);
            if(iter!=vec_nums.end()) iter->second=iter->second+1;
            if(iter==vec_nums.end()) vec_nums.insert(pair<int,int>(nums[i],1));
        }
        map<int,int>::iterator iter;
        for(iter=vec_nums.begin();iter!=vec_nums.end();iter++){
            if(iter->second >nums.size()/2)
            return iter->first;
        }
        return 0;
    }
    
};
```