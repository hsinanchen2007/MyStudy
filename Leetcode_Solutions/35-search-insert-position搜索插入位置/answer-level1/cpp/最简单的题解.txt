
c++
考虑三种情况就好。
```c++ []
class Solution {
public:
        int searchInsert(vector<int>& nums, int target) {
        int n=(int)nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i]==target)//等于时正好找到i;
            return i;
            if(target<nums[i])//小于时插在该元素前面，所以就返回i;
            return i;
            if(target>nums[n-1])//考虑到大于最后一个元素，插在末尾返回n;
            return n;
        }
        return 0;
    }
};
```
