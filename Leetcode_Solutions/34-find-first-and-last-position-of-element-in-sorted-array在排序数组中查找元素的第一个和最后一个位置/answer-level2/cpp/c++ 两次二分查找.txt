### 解题思路
本题最开始的做法是直接使用双指针的思想，左右夹逼，直到找到初始值和末尾值。
但是发现这种做法，不符合题目的要求，所以，就换了另一种方法。

我们可以看到O(log n)的时间复杂度，一般来说是二分查找。
但是二分查找可以找到对应的值，并不能一次就找到初始位置和末尾位置。

因此，使用两次二分查找，先找左边位置。再找右边的位置，就可以了。
使用二分查找的时候，一定要注意判定条件。
当找左边的时候：
只有中值对应的值小于target的时候，我们才变动left的值。
其他情况下，一率变动right的值。
当找右边的时候：
只有中值对应的值大于target的时候，我们才变动right的值。
其他情况下，一率变动left的值。
这样得到的值才是想要的left和right的值。

然后，再存入right的值的时候，又一个问题，就是什么时候存right，什么时候存right-1；
这个可以进行一下判定，如果right对应的值等于target，则正好处于边界。
如果不等于target，则说明其下一个值就是边界。

### 代码

```cpp
class Solution {
public:
    //按照升序排列，可以二分查找
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int medium = 0;
        vector<int> res;
        if(nums.size() == 0) return res = {-1,-1};
        //找左边
        while(left < right){
            medium = left + (right - left) /2;
            if(nums[medium] == target) right = medium;
            else if (nums[medium] < target) left = medium + 1;
            else right = medium;
        }
        if(nums[left] != target) return res = {-1,-1};
        //这个地方是把左值放进去了。
        res.push_back(left);
        //找右边
        left = 0;
        right = nums.size()-1;
        while(left < right){
            medium = left + (right - left) / 2;
            if(nums[medium] == target) left = medium + 1;
            else if(nums[medium] > target) right = medium;
            else left = medium + 1;
        }
        if(nums[right] == target) res.push_back(right);
        else res.push_back(right-1);
        return res;
    }
};
```