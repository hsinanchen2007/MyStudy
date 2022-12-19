### 解题思路
两种做法：
1.先找到旋转后的最小值的索引，然后对两端执行二分查找。官方题解对于边界条件判断实在太繁琐了，也不好想。利用binary_search先判断是否不能再，然后利用lower_bound获得结果。
2.对数组进行索引编号记录，然后排序，排序后使用基本的二分查找算法。

**推荐使用第二种方法，简单通用**


1.找到旋转后的最小值的索引
可参考如下做法：
153. 寻找旋转排序数组中的最小值
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/
注意两点：
1）与右边界比较：要取左侧地板值，mid偏向left。
当nums[mid]>nums[right]时，nums[mid]一定不是最小值，因此left = mid+1;
当nums[mid]<=nums[right]时，nums[mid]有可能是最小值，因此right = mid
最小值取left
2）与左边界比较：要取右侧地板值，mid偏向right。
当nums[mid]>=nums[left]时，nums[mid]可能是最大值，因此left = mid;
当nums[mid]<nums[left]时，nums[mid]一定不可能是最大值，因此right = mid-1;
最大值取left

2.找到最小值索引后，使用二分查找
注意一点：
binary_search（begin，**begin+length**，val） 迭代器使用方式
lower_bound(begin，**begin+length**，val)  迭代器使用方式




### 代码

```cpp
class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int minindex = left;
        if (binary_search(nums.begin(), nums.begin() + minindex, target)) {
            return lower_bound(nums.begin(), nums.begin() + minindex, target) - nums.begin();
        }

        if (binary_search(nums.begin() + minindex, nums.end(), target)) {
            return lower_bound(nums.begin() + minindex, nums.end(), target) - nums.begin();
        }

        return -1;
    }
};
```

2.对数组进行索引编号记录，然后排序，排序后使用基本的二分查找算法。

**推荐使用第二种方法，简单通用**

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<vector<int>> indexpair;

        for (int i = 0; i < nums.size();i++){
            indexpair.push_back(vector<int>{nums[i], i});
        }

        sort(indexpair.begin(), indexpair.end());

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left<=right){
            mid = left + (right - left) / 2;
            if(indexpair[mid][0] == target){
                return indexpair[mid][1];
            }else if(indexpair[mid][0] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return -1;
    }
};
```
