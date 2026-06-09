思路:由于是求最大子序列和，所以对于sum来说前面累加的数组<0，那么抛掉前面累加的元素重新归零。依次遍历求出连续子序列的最大值即可。
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        int Sum,MaxSum;
        Sum=0,MaxSum=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            Sum+=nums[i];
            if(Sum>MaxSum)
                MaxSum=Sum;
            if(Sum<0)
                Sum=0;
        }
        return MaxSum;
    }
};

```
