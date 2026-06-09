三指针。

设置三个指针 left = 0, right = nums.size() , i = 0, 其中 left 为左侧 0 的个数，right 指向从后先前数的最后一个 2.

指针 i 用来遍历，每次遇到 0, 则将它与 left 上数值交换，且 i++,left++; 每次遇到 2, 则将它与 right - 1 上的值交换，并且 right--; 每次遇到 1, 单纯 i++.

代码：
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for( int left = 0, right = nums.size(), i = 0; i < right; )
            if( nums[i] == 0)
                swap( nums[i], nums[left]), left++, i++;
            else if( nums[i] == 2)
                swap( nums[i], nums[right-1]), right--;
            else
                i++;
    }
};
```