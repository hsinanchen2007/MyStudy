### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            sum += nums[i];
            nums[i] = sum;
        }

        for (int i = 0; i < sz; ++i) {
            int left = (i - 1 >= 0) ? nums[i - 1] : 0;
            int right = sum - nums[i]; 
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};
```