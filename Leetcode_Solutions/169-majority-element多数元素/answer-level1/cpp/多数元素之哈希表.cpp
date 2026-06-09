### 解题思路
1.哈希表遍历一遍统计每个数字出现的次数，此过程需要时间O(n)
2.然后再遍历一遍数组找到出现次数超过数组一半的元素，需要时间O(n)
3.时间复杂度O(n),空间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int>hash;
        for(int i = 0;i < nums.size();i++)
        {
            hash[nums[i]]++;
        }

        for(int i = 0;i < nums.size();i++)
        {
            if(hash[nums[i]] > nums.size()>>1)
            {
                return nums[i];
            }
        }
        return 0;
    }
};
```