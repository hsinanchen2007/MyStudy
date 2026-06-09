- 思路：
  - 动态规划，opt[n]=max(opt[n-2]+nums[n],opt[n-1])
- 时间复杂度：
  - o(n)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：63%（4ms）
  - 内存：100%
```
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()>=2) nums[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            nums[i]=max(nums[i-2]+nums[i],nums[i-1]);
        }
        return nums[nums.size()-1];
    }
};
```
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------
