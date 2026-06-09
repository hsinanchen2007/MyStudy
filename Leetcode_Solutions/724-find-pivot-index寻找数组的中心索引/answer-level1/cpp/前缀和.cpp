### 解题思路
1. 先求出整个数组的的前缀和sum
2. 依次通过数组下标扫描数组的元素，看该下标是否符合中心索引，若符合，返回该下标

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        int left_sum = 0;
        for(int i=0;i<nums.size();i++){
            if(left_sum + left_sum == sum - nums[i]) return i;
            left_sum += nums[i];
        }
        return -1;
    }
};
```