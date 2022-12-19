- 思路：
  - 由于是乘法，存在负负得正的情况，dp数组需要存储当前结尾的最大值和最小值
- 时间复杂度：
  - o(n)
- 空间复杂度：
  - o(1)
- 结果:
  - 用时：100%（0ms）
  - 内存：5%（14.3MB）
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_res=nums[0],tmp_max=nums[0],tmp_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int t_max=max(nums[i],max(nums[i]*tmp_max,nums[i]*tmp_min));
            int t_min=min(nums[i],min(nums[i]*tmp_max,nums[i]*tmp_min));
            tmp_max=t_max,tmp_min=t_min;
            if(t_max>max_res) max_res=t_max;
        }
        return max_res;
    }
};
```