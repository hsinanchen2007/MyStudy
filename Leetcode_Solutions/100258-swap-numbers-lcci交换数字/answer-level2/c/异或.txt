
### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& nums) {
        nums[0]^=nums[1]^=nums[0]^=nums[1];
        return nums;
    }
};
```