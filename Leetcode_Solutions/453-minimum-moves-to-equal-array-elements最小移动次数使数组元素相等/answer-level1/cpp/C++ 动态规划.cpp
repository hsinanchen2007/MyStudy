### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int res = 0;
        sort(nums.begin(),nums.end());
        int temp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int t = res;
            res += nums[i] + res - temp;
            temp = nums[i] + t;
        }
        return res;
    }
};
```