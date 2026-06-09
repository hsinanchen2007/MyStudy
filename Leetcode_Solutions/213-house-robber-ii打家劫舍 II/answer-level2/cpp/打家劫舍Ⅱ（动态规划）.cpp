### 解题思路

分两种情况
### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return nums[0] > nums[1] ? nums[0] :nums[1];
        int c1[n], c2[n];
        c1[0] = nums[0];
        c1[1] = nums[0] > nums[1] ?nums[0] :nums[1];
        c1[2] = max(c1[1], c1[0] + nums[2]);
        c2[1] = nums[1];
        c2[2] = nums[1] > nums[2] ?nums[1] :nums[2];

        for(int i = 3; i < n; i++){
            c2[i] = max(c2[i-1], c2[i-2] + nums[i]);
            c1[i] = max(c1[i-1], c1[i-2] + nums[i]);
        }

        return max(c1[n-2], c2[n-1]);
    }
};
```