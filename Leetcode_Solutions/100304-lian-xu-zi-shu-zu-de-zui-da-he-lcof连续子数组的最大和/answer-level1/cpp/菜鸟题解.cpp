### 解题思路
对数组遍历的同时记录每一个数的最大和

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;
        int map[n];
        for(int k = 0;k<n;k++)
        map[k] = 0;

        map[0] = nums[0];
        for(int i = 1;i<n;i++)
            map[i] = max(nums[i],nums[i]+map[i-1]);

        return *max_element(map,map+n);
        

    }
};
```