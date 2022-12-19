```
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size(),0);
        if(nums.size()<=0) return false;
        sum[0]=nums[0];
        int i,j;
        for(i=1;i<nums.size();i++){
            sum[i]+=sum[i-1]+nums[i];
        }
        int flag=0;
        for(i=0;i<nums.size();i++){
            for(j=i+1;j<nums.size();j++){
                int s1=sum[j]-sum[i]+nums[i];
                if(k!=0&&s1%k==0){
                    return true;
                }
                if(k==0&&s1==0) return true;
            }
        }
        return false;
    }
};
```
