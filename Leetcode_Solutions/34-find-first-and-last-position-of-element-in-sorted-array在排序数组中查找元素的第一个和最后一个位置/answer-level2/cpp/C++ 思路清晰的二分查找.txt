### 解题思路

### 1. 看题初印象

我看到这题目的时候首先不管什么效率不效率的，直接**暴力搜索**——前后双指针。找到target就停止指针移动；
> 空间复杂度 O(1); 时间复杂度最差 O(n),最好O(1)

这个代码就不列出来了，过于简单啦~~~

### 2. 二分查找

对于这种有序数组，查找某一个target的，使用二分法再合适不过了。接下来我来说一下我的思路：

+ 先对数组做一次二分查找，范围是`start = 0， end = nums.size()-1`，随便找到一个target的索引位置 index
+ 如果 `index == -1` (意思是找不到)，那么可以直接return了
+ 接下来查找左边界`left_end`，首先`left_end == index - 1`，然后对`start = 0 ，end = left_end`的范围不断运用二分查找，直到`nums[left_end] < target`，此时左边界就是`left_end`
+ 接下来查找右边界`right_start`，首先`right_start == index + 1`，然后对`start = right_start ，end = nums.size()`的范围不断运用二分查找，直到`nums[right_start] > target`，此时右边界就是`right_start`


**就是这样的啦，来看看代码伐~~~**


### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        int index  = search(nums, 0 ,nums.size()-1, target);
        if(index == -1) return res;
        // 开始左查找
        int left_end = index - 1;
        while(left_end >= 0 && nums[left_end] == target){
            left_end = search(nums, 0, left_end, target) - 1;
        }
        // 开始右查找
        int right_start = index + 1;
        while(right_start < nums.size()  && nums[right_start] == target){
            right_start = search(nums, right_start, nums.size()-1, target) + 1;
        }
        //  left_end 和 right_start 进行组合
        res[0] = min(index, left_end + 1);
        res[1] = max(index, right_start - 1);
        // 返回结果
        return res;
    }
private:
    int search(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};
```