```
![image.png](https://pic.leetcode-cn.com/ae8f1de3682cb099876aa7bcc4319408d803c4a4e3f845eedb970c537407f2cf-image.png)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int n=nums.size();
        int k=-1;//开始就为最大值
        for(int i=n-1;i>0;i--)
            if(nums[i-1]<nums[i]){
                k=i-1;
                break;
            }
        if(k>=0){
            for(int j=n-1;j>k;j--)
                if(nums[j]>nums[k]){
                    swap(nums[k],nums[j]);
                    break;
                }
        }
        reverse(nums.begin()+k+1,nums.end());
    }
};
```
