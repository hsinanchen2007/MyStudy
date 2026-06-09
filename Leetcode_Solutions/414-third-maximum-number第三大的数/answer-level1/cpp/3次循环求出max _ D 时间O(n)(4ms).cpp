![image.png](https://pic.leetcode-cn.com/c8972806e3fbb972f195079b07badb7e114aeb05eada20e0fb26d98dcbdba8b2-image.png)
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,n=nums.size(),cnt=0;//具体看代码就知道啦
        for(int i=0;i<n;i++)max1=max(max1,nums[i]);
        for(int i=0;i<n;i++)if(nums[i]!=max1)max2=max(max2,nums[i]);
        for(int i=0;i<n;i++)if(nums[i]!=max1&&nums[i]!=max2){
            if(nums[i]>=max3){
                max3=nums[i];
                cnt++;
            }
        }
        return (cnt==0)?max1:max3;
    }
};
```

