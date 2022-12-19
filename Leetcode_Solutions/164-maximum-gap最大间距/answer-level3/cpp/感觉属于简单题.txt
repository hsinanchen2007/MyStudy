```
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res = INT_MIN;
        for(int i = 1; i < len; i++){
            res = max(res,nums[i] - nums[i-1]);
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/0c56e52e944c947daf06894b162624e6c1645c598936e3efcab7e93a42e878c7-1.png)
