

### 代码

```cpp
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==i) return nums[i];
        return -1;
    }
};
```