### 思路

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, 1), right(size, 1), res(size);
        for (int i = 0; i < size - 1; ++i) {
            left[i + 1] = left[i] * nums[i];
        }
        for (int i = size - 1; i > 0; --i) {
            right[i - 1] = right[i] * nums[i];
        }
        for (int i = 0; i < size; ++i) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};
```