估计是测试集的原因，用下面暴力求解能过：
思路：
- 判断数组是否是升序或降序排列
- 按升序或降序相邻比较
- 若打破了升（降）序，则从之前最后一个去查找，并交换位置

```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2) {
            return false;
        }
        if (nums.front() < nums.back()) {
            for (int i = 0; i < nums.size()-1; i++) {
                if (nums[i] < nums[i+1]) {
                    continue;
                } else if (nums[i] == nums[i+1]) {
                    return true;
                } else if (findNum(nums, i, nums[i+1])){
                    return true;
                } else {
                    int tmp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = nums[i];
                }            
            }
        } else if (nums.front() == nums.back()) {
            return true;
        } else {
            for (int i = 0; i < nums.size()-1; i++) {
                if (nums[i] > nums[i+1]) {
                    continue;
                } else if (nums[i] == nums[i+1]) {
                    return true;
                } else if (findNum(nums, i, nums[i+1])){
                    return true;
                } else {
                    int tmp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = nums[i];
                }            
            }
        }
        return false;
    }
    
private:    
    bool findNum(vector<int>& nums, int end, int data) {
        while (end >= 0) {
            if (nums[end] == data) {
                return true;
            }
            end--;
        } 
        return false;
    }
    
};
```
