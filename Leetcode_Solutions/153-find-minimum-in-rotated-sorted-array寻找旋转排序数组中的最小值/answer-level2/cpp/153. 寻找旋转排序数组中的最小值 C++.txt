### 解题思路
二分查找找最大值或者最小值
1）直接找最小值：
2）找最大值:（最大值索引+1）%nums.size() 是最小值索引

参考的题解：
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-cha-zhao-wei-shi-yao-zuo-you-bu-dui-cheng-z/

取最小值
1）这里的循环不变式是left < right, 并且要保证左闭右开区间里面始终套住最小值。
2）中间位置的计算：mid = left + (right - left) / 2
这里整数除法是向下取整的地板除，mid更靠近left，

```cpp
class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid ;
            } else {
                right = mid-1;
            }
        }

        return nums[left];
    }
};
```

取最大值
1）这里的循环不变式是left < right, 并且要保证左开右闭区间里面始终套住最大值。
2）中间位置的计算：mid = left + (right - left+1) / 2
这里整数除法是向上取整的地板除，mid更靠近right，

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left+1) / 2;
            if (nums[mid] >= nums[left]) {
                left = mid ;
            } else {
                right = mid-1;
            }
        }

        return nums[(left+1)%nums.size() ];
    }
};

```