### 解题思路
求左边界和右边界的可以当做固定的套路来记。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1,-1};
        int leftbound = -1;
        int rightbound = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {//二分法找左边界
            int mid = left + (right - left) / 2;//如果剩下两个数mid为前一个
            if(nums[mid] < target)//要求左边的边界，所以希望mid严格小于target，这样左边界才能包含在下次迭代
                left = mid + 1;
            else 
                right = mid;
        }
        if(nums[left] == target)
            leftbound = left;

        left = 0;
        right = nums.size() - 1;
        while(left < right) {//二分法查找右边界
            int mid = left + (right - left + 1) / 2;//这里有+1 如果剩下两个数 mid为后一个
            if(nums[mid] > target)//要求右边的边界，所以希望mid严格大于target，这样右边界才能包含在下次迭代
                right = mid - 1;
            else
                left = mid;
        }
        if(nums[right] == target)
            rightbound = right;
        return{leftbound,rightbound};
    }
};
```