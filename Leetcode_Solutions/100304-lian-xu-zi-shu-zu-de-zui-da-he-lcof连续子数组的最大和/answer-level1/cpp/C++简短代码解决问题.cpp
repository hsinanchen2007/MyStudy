```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int M=nums[0],p=0;
        //M记录子数组的和的最大值，初始化为nums[0]
        //p记录子数组累加过程的数值，初始化为0
        for(int i=0;i<nums.size();i++){
            M=max(p+=nums[i],M);
            p=max(p,0);
            //p每次循环累加nums[i]
            //M每次循环与累加后的p比较，取大值
            //当p小于0时，当前的p值继续往下进行无意义，所以把p重新初始化为0
        }
        return M;
    }
};
```
