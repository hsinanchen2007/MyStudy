### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = -1; // [l,r]为滑动窗口
        int res = nums.size()+1;
        int cursum = 0;
        while (l < nums.size()) {
            // 一定要保证每次移动左边界或右边界都会变化
            if(r + 1 < nums.size() && cursum < s) { //满足条件移动右边界
                cursum += nums[r + 1];
                r++;
            } else { // r已经到头，或者cursum>=s，都需要移动左边界
                cursum -= nums[l];
                l++;
            }
            
            if(cursum >= s) {
                res = min(res, r-l+1);
            }
        }
        if(res == nums.size() + 1) {
            return 0;
        }
        return res;    
    }
};
```