class Solution {
public:
    bool dfs(vector<int> groups,int sisum,vector<int> nums,int ans){
         if(ans<0)
           return true;
         for(int i=0;i<groups.size();++i){
             if(groups[i]+nums[ans]<=sisum){
                 groups[i]+=nums[ans];
                 if(dfs(groups,sisum,nums,ans-1))
                   return true;
                 groups[i]-=nums[ans];
             }
             if(groups[i]==0){
                 break;
             } 
         }
         return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
           int sum=0;
           for(int i=0;i<nums.size();++i){
                sum=sum+nums[i];
           }
           if(sum%k!=0)
                return false;
           sort(nums.begin(),nums.end());
           if(nums[nums.size()-1]>sum/k)
                return false;
           vector<int> groups(k,0);
           return dfs(groups,sum/k,nums,nums.size()-1);
    }
};