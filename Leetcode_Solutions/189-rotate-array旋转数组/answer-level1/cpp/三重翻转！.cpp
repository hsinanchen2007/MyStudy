### 解题思路
1.移动位置大于数组的，取余后简化操作
2.手写三重翻转

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return;
        k %= nums.size();
        //左半部分翻转
        for (int i=0; i<(nums.size()-k)/2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[nums.size()-1-k-i];
            nums[nums.size()-1-k-i] = temp;
        }
        //右半部分翻转
        for (int i=0; i<k/2; i++)
        {
            int temp = nums[nums.size()-k+i];
            nums[nums.size()-k+i] = nums[nums.size()-1-i];
            nums[nums.size()-1-i] = temp;
        }
        //整个数组翻转
        for (int i=0; i<nums.size()/2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[nums.size()-i-1];
            nums[nums.size()-i-1] = temp;
        }
    }
};
```