### 解题思路
官方题解c++版；
- 遍历输入数组的每个元素一次。
- 我们将把 |nums[i]|-1 索引位置的元素标记为负数。即 nums[|nums[i] |- 1] = nums[∣nums[i]∣−1]×−1 。
- 然后遍历数组，若当前数组元素 nums[i] 为负数，说明我们在数组中存在数字 i+1。


### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};
```