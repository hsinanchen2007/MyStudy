循环遍历该数组，判断当前元素nums[i]和nums[i+2]元素的值，若相等，则删除当前元素nums[i]；若不相等，则继续移动i，做i++。因为给定数组已经排好序，要使每个元素最多出现两次，只需隔2位比较。
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
                nums.erase(nums.begin() + i);
            }
            else {
                i++;
            }
        }
        return nums.size();
    }
};
```
