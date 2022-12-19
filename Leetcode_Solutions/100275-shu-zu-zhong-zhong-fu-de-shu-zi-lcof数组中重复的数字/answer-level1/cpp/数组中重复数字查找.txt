### 解题思路
空间效率优先，对原数组进行修改，类似于排序算法，将第i个位置的数与第nums[i]位置的数进行交换，直到i==nums[i],如果在置换的过程中发现某个位置已经满足条件，且此数字也要放到第i个位置，即发生了冲突，此数发生重复。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};
```