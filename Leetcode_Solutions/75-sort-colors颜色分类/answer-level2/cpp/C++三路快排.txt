### 解题思路
三路快排

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, cur = 0, two = nums.size();
        while(cur < two)
        {
            if(nums[cur] == 1)
                cur++;
            else if(nums[cur] == 0)
                swap(nums[++zero], nums[cur++]);
            else //nums[cur] == 2
                swap(nums[cur], nums[--two]);
        }
    
    }
};
```