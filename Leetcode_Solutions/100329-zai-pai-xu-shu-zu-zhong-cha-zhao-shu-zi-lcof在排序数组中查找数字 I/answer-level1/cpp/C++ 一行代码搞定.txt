

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return count(nums.begin(),nums.end(),target);
    }
};
```