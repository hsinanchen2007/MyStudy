### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            if((nums[left] & 1) != 0) //左指针找偶数
            {
                left++;
                continue;
            }
            if((nums[right] & 1) == 0)//右指针找奇数
            {
                right--;
                continue;
            }
            swap(nums[left], nums[right]);
        }
        return nums;
    }
};
```