### 解题思路
- 采用map<int,int> res来记录数组的元素和出现次数；
- 先遍历数组，记录每个元素的出现次数；
- 接着再次遍历，将出现次数超过nums.size()/2的元素输出即可

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    if(nums.size() < 0) return -1;
    map<int,int> res;
    
    for(auto i : nums)
    {
        res[i]++;
    }
    for(auto i : nums)
    {
        if(res[i] > nums.size()/2)
            return i;
    }
    return -1;      
    }
};
```