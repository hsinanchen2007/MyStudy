[@liweiwei1419](/u/liweiwei1419/)
![TIM图片20191209173112.png](https://pic.leetcode-cn.com/fb7ccc68d91609a7fe8868dbefe487d936bafa53a938ff6b1e675171df676522-TIM%E5%9B%BE%E7%89%8720191209173112.png)
``` []
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>::size_type n=nums.size();
        if(n==0) return 1;
        for(size_t i=0;i<n;i++) {
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]&&i+1!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(size_t i=0;i<n;i++) {
            if(i+1!=nums[i])
                return i+1;
        }
        return n+1;
    }
};
```
