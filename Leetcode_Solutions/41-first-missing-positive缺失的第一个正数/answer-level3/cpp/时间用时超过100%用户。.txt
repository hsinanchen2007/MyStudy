### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a3dc4657c62fbae3d846edbcbb676b153b1d8c349fc28bbc806385c33532b6c7-image.png)



因为是无序数组，第一想法排序。
设置双指针，一个i代表有序数字，一个j代表数组。
主要想法是 nums[j]<=i<nums[j+1].


### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=1,len=nums.size();
        for (int j=0;j<len;j++){
            if(i==nums[j]) i++;
            else if(i<nums[j]) break;
        }
        return i;
    }
};
```