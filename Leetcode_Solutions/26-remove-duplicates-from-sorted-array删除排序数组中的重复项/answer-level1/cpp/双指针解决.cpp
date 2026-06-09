### 解题思路
利用双指针即可解决，
first second， second不断往前移动；first是如果和second不相等，将second赋值给first+1，然后++first

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int first = 0;
        int second = 1;
        for (;second < nums.size(); ++second) {
            if (nums[second] != nums[first]) {
                nums[first+1] = nums[second];
                ++first;
            }
        }
        return first+1;
    }
};
```