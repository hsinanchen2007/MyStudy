### 解题思路
**方法一：哈希映射**
时间复杂度：O[N]
空间复杂度：O[N]
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> num_map;
        for(int i = 0; i<nums.size();i++)
        { 
            num_map[nums[i]]++;
        }  
        for(int i = 0; i<nums.size();i++)
        { 
           if( num_map[nums[i]]==1)
           {
               return nums[i];
           }
        }
        return 0;
    }
};
```