### 解题思路
直接下标不相等就返回

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)
                break;;
        }
        return i;
    }
};
```