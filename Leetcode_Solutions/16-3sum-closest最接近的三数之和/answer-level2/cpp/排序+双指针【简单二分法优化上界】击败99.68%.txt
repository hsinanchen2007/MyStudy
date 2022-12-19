![捕获.PNG](https://pic.leetcode-cn.com/f1df3b4c50af3f4b3df050d07380e0bc2ea1d90cda2b5f966b26f4e8eed63063-%E6%8D%95%E8%8E%B7.PNG)
```cpp []
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //升序排序
        sort(nums.begin(),nums.end());
        //二分法优化上界(含)
        int l(0);
        int r(nums.size()-3);
        int mid;
        int sum;
        while(l<r){
            mid=(l+r)>>1;
            sum=nums[mid]+nums[mid+1]+nums[mid+2];
            if(sum<target)
                l=mid+1;
            else if(sum==target)
                return target;
            else
                r=mid;
        }
        //用上界l初始化res
        int res(nums[l]+nums[l+1]+nums[l+2]);
        //常规双指针
        for(int i=0;i<l;++i){
            //重复，跳过
            if(i&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1,k=nums.size()-1;j<k;){
                int sum=nums[i]+nums[j]+nums[k];
                res=abs(sum-target)<abs(res-target)?sum:res;
                if(sum==target)
                    return target;
                else if(sum<target)
                    ++j;
                else
                    --k;
            }
        }
        return res;
    }
};
```
