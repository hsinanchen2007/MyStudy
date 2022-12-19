### 解题思路
双指针 滑动窗口

### 代码

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int size = (int)nums.size();
        int rs = 0;
        int i = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0;j < size;j++) {
            //nums[j] - nums[i] > 1 说明nums[i]太小了，需要变大
            while (i < size && nums[j] - nums[i] > 1) {
                i++;
            }
            if(nums[j] - nums[i] == 1){
                rs = max(rs,j-i+1);
            }
        }
        return rs;
    }
};
```