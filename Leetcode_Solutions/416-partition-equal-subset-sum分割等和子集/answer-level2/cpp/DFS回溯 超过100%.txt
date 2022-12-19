排序后从大往小DFS，从小往大会被1，1，1，1，......这样的数据卡TLE
一旦出现超过sum剪枝
```
class Solution {
public:
    bool DFS(int i,int cur,int sum,vector<int>&nums){
        for(int j=i-1;j>=0;j--){
            if(cur+nums[j]==sum) return true;
            if(cur+nums[j]>sum) continue;
            if(DFS(j,cur+nums[j],sum,nums)) return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        long sum=0;
        for(int x:nums) sum+=x;
        if(sum%2) return false;
        sum/=2;
        sort(nums.begin(),nums.end());
        if(nums.back()>sum) return false;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==sum) return true;
            if(DFS(i,nums[i],sum,nums)) return true;
        }
        return false;
    }
};
```