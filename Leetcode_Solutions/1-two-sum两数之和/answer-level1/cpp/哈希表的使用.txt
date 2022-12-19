### 解题思路
本道题主要考察哈希表的使用,利用哈希表我们可以在O(n)时间内完成查找nums数组中是否存在target - nums[i]这个值，特别需要注意的是考虑返回的下标值是去重复的，比如在用例是nums=[3 2 4],target=6时，不能输出0,0。
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        
        unordered_map<int,int>map;
        
        for(int i = 0; i< nums.size();i++)
        {
            map[nums[i]] = i;
        }

        for(int i = 0;i<nums.size();i++)
        {
            if(map.count(target - nums[i]) && map[target-nums[i]] != i)
            {
                return {i,map[target - nums[i]]};
            }
        }
        return{};
    }
};
```