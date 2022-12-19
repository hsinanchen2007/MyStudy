因为输入的数组本来就是有序的，所以一旦第i个数较大就停止搜索返回索引，若数组最后一个数都比目标值小，则返回数组的长度
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] >= target)
                return i;
            
            if(nums[nums.size()-1] < target)
                return nums.size();
        }
        return i;
    }
};
```
