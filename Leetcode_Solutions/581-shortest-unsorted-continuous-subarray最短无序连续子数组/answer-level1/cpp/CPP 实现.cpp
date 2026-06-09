### 解题思路
1. 四次遍历方法
2. sort之后比对的方法

### 代码

```cpp
class Solution {
public:
    //四次遍历
    //1. 先从左边 找出降序的第一个元素, 从这里开始找，找出最小的元素值 min
    //2. 从右边找出升序的第一个元素，从这里开始找，找出最大的元素 max
    //例子1： 2 6 4 8 13 9 10 12,  min=4,  max = 13
    //从左边找出第一个比min大的元素 6，从右边找到第一个比 max小的元素，12
    //例子2：  1 3 5 4 2    min=2, max = 5
    ///从左边找出第一个比min大的元素 3，从右边找到第一个比 max小的元素，2
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = nums.size();
        int min = INT_MAX, max = INT_MIN;
        int flag = false;
        for(int i=1; i<len; ++i)
        {
            if(nums[i]<nums[i-1])
                flag = true;
            if(flag)
                min = std::min(min, nums[i]);
        }
        flag = false;
        for(int j=len-2; j>=0; --j)
        {
            if(nums[j]>nums[j+1])
                flag = true;
            if(flag)
                max = std::max(max, nums[j]);
        }
        int left=0, right=len-1;
        for(; left<len-1; ++left)
        {
            if(nums[left]>min)
            {
                break;
            }
        }
        for(; right>=0; --right)
        {
            if(nums[right]<max)
            {
                break;
            }
        }
        return (right-left)<=0 ? 0 : (right-left+1);
    }

    //sort之后比较
    int findUnsortedSubarray1(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> copy = nums;
        int len = nums.size();
        sort(copy.begin(), copy.end());
        int left=0, right=len-1;
        for(; left<len; ++left)
        {
            if(nums[left]!=copy[left])
                break;
        }
        for(; right>=0; --right)
        {
            if(nums[right]!=copy[right])
                break;
        }
        return (right-left)<=0 ? 0 : (right-left+1);
    }
};
```