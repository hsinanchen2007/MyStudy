### 解题思路
需要复制一次数组，然后利用冒泡排序优化算法的思想，正着遍历一遍找出最后一次交换的位置，然后逆着遍历一遍找出最后一次交换的位置，就是左右无序数组的开始结束位置。

### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int left = -1;
        int right = -1;
        vector<int> nums1 = nums;
        for(int i = 0; i < nums1.size()-1; i++)
        {
            if(nums1[i] > nums1[i+1])
            {
                right = i+1;
                swap(nums1[i], nums1[i+1]);
            }
        }
        if(right == -1)  return 0;
        nums1 = nums;
        for(int j = nums1.size()-1; j > 0; j--)
        {
            if(nums1[j] < nums1[j-1])
            {
               left = j-1;
               swap(nums1[j], nums1[j-1]);
            }
        }
        return right - left+1;
    }
};
```