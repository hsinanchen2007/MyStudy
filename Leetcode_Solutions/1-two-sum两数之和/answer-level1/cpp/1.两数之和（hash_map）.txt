### 解题思路
核心要点：建立hash表，遍历一趟即可查出有无结果
### 代码

```cpp
#include<hash_map>
using namespace __gnu_cxx;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2);
        hash_map<int,int>nmap;
        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            if(nmap.find(n)!=nmap.end()){
                result[0]=nmap.find(n)->second;
                result[1]=i;
                return result;
            }
            nmap.insert(pair<int,int>(nums[i],i));
        }
        return result;
    }
};
```