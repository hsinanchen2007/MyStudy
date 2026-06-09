### 解题思路
看的官方题解

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int cur = 0;
        while (cur <= r) {   //此处注意
            if (nums[cur] == 2) {
                swap(nums[cur], nums[r--]);
            } else if (nums[cur] == 0) {
                swap(nums[cur++], nums[l++]);
            } else {
                cur++;
            }
        }
    }
};
```