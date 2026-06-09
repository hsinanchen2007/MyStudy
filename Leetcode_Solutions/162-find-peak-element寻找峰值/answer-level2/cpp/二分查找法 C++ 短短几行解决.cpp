### 解题思路
由于时间复杂度为o(logn)因此不同用遍历的方法 
使用二分查找和递归的方式 用以下几行代码可以解决

和以前的二分查找法类似，如果目标值大于了中间值，说明我们就应该去右边寻找目标值
这里将目标值换成峰值，如果中间值后面的值大于当前中间值 说明当前趋势是上升，因此我们应该去后面寻找
反之，如果是下降趋势，那么峰值应该在中间值的前方，我们应该去前面查找
### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int>& nums, int left, int right){
        if(left == right) return left;
        int middle = (left + right) / 2;
        if(nums[middle] < nums[middle+1]) return search(nums, middle + 1, right);
        else return search(nums, left, middle);
    }
};
```