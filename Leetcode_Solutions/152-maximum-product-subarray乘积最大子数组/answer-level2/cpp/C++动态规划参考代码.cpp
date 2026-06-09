![image.png](https://pic.leetcode-cn.com/9129737b8f9adeb813811961e143a89b957a8d6cd55b7a27896d42fbc029942b-image.png)

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        int res = 0, dp0, dp1;
        for(int i = 0; i < nums.size(); i++){
            if(!i)
                dp0 = nums[0], dp1 = nums[0];
            else{
                int temp = dp0;
                dp0 = max(nums[i]*dp0, max(nums[i], nums[i]*dp1));
                dp1 = min(nums[i]*temp, min(nums[i], nums[i]*dp1));
            }
            res = res > dp0 ? res : dp0;
        }
        return res;
    }
};
```
