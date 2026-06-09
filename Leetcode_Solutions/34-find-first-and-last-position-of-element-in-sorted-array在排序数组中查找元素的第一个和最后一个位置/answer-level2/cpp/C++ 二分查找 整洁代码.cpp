### 解题思路
此处撰写解题思路

### 代码

```cpp
/* 二分查找定界问题：
 * 1. 何时缩短边界 2. 何时结束 3. 结束时返回什么
 *
 * 针对问题1 3
 *  a. 第一个>= target位置
 *      显然要缩短右边界 返回左边界
 *  b. 最后一个>= target位置
 *      缩短左边界      返回右边界
 *  最后注意判断l h是否越界。如果是要求 == target 最后返回时也要判断是否相等
 *
 * 针对问题2
 *      区间长度不合法时： low > high
 * */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())    return {-1, -1};
        int low = lower(nums, target), up = upper(nums, target);
        return {low, up};
    }

    int lower(vector<int>& nums, int target){
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            int m = (l + h) / 2;
            if(nums[m] >= target)   h = m - 1;
            else l = m + 1;
        }
        //cout<<"low: "<<l<<endl;
        return (l < nums.size() && nums[l] == target) ? l : -1;
    }
    int upper(vector<int>& nums, int target){
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            int m = (l + h) / 2;
            if(nums[m] <= target)   l = m + 1;
            else h = m - 1;
        }
        //cout<<"high: "<<h<<endl;
        return (h < nums.size() && nums[h] == target) ? h : -1;
    }
};
```