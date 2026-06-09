1.对nums快速排序
2.用for循环确定三元组的第一个数i,对于剩下的两个数,设置双指针j=i+1,k=nums.size()-1,从两个前后两个方向搜寻最小值
和前一题差别不大。

```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int min=0,minres=0;//min表示三书之和与target的差值
        int j=0,k=0;
        minres=nums[0]+nums[1]+nums[nums.size()-1];
        min=abs(minres-target);
        
        if(nums.size()==3)
            return minres;
        
        for(int i=0;i<nums.size()-2;i++){
            j=i+1;k=nums.size()-1;
            while(j<k){
                if(min==0)
                    return minres;
                if(abs(nums[i]+nums[j]+nums[k]-target)<min){
                    minres=nums[i]+nums[j]+nums[k];
                    min=abs(minres-target);
                }
                if(nums[i]+nums[j]+nums[k]-target<0)
                    j++;
                else
                    k--;
            }
        }
        return minres;
    }
};
```
结果：
![TIM截图20190923154655.png](https://pic.leetcode-cn.com/95b010fcd1d054cb3c0d9059803a7b26b5d5a272905bcd3d90c4142025f387b6-TIM%E6%88%AA%E5%9B%BE20190923154655.png)

