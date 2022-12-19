### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_len = 0;
        for(int i = 0;i<nums.size();i++){
            int sum = nums[i];
            int p_len = 1;
            int j = i;
            while(sum<s&&(++j<nums.size())){
                sum += nums[j];
                ++p_len;
            }
            if(sum>=s) {
                if(min_len==0) min_len = p_len;
                else min_len = min_len<p_len?min_len:p_len;
            }
        }
        return min_len;
    }
};
```