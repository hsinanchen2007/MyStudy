### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (0 == nums.size())
        {
            return false;
        }

        unordered_map<int, int> map;

        for(int index = 0; index <= nums.size() - 1; index++)
        {
            if(NULL != map.count(nums[index]) && index - map[nums[index]] <= k) 
            {
                return true;
            }

            map[nums[index]] = index;
        }
        return false;
    }
};

```