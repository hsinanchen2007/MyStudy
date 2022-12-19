**C++暴力可过，需要注意几个条件**
* 筛选时只筛选nums[i]/2的部分
* 当找到的因数大于4时立即break
```
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int count = 0;
            int t = 0;
            for(int j = 2; j <= nums[i]/2; ++j){
                if(nums[i] % j == 0){
                    count++;
                    t = j;
                }
                if(count > 2)
                    break;
            }
            if(count == 2)
                res += (1+nums[i]+t+nums[i]/t);
        }
        return res;
    }
};
```