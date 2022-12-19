处理类似[1,5,4,3,2]的情况时为最差时间复杂度O(2N + NlogN) ~= O(N), 空间复杂度O(1)

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1; i>0; --i){
            // 从后往前找到第一个升序位置
            if(nums[i]>nums[i-1]) {
                // 从前向后找出大于待交换点的最小值
                int min = nums[i];
                int idx = i;
                for(int j=i+1; j<nums.size(); ++j){
                    if(nums[j] > nums[i-1] && nums[j] < min){
                        min = nums[j];
                        idx = j;
                    }
                }
                // 交换
                int tmp = nums[i-1];
                nums[i-1] = nums[idx];
                nums[idx] = tmp;
                // 排序剩余数据
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        // 未找到升序位置，则为完全降序，需要重新排序
        sort(nums.begin(), nums.end());
    }
};
```