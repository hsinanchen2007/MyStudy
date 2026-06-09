### 解题思路
先用快速排序

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++,count++)
        {
            if(count != nums[i])
            {
                res = count;
                break;
            }        
        }
        return res;
    }
};
```