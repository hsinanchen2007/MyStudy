回溯求解，
正常形式：
```
bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/k;
        vector<int> paths(k,0);
        sort(nums.rbegin(),nums.rend());
        return helper(paths,nums,target,0);
    }
    bool helper(vector<int>& paths,vector<int>& nums,int target,int level){
        if(level>=nums.size()) {
            for(auto path:paths){
                if(path!=target) return false;
            }
            return true;
        }
        for(int i=0;i<paths.size();i++){
            if(paths[i]+nums[level]>target) continue;
            paths[i]+=nums[level];
            if(helper(paths,nums,target,level+1)) return true;
            paths[i]-=nums[level];
        }
        return false;
    }
```

另一种形式（因为这样会跳过有些元素，会导致重复计算很多次，因此耗时严重，本题中TLE）
```
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/k;
        sort(nums.rbegin(),nums.rend());
        vector<int> paths(k,0);
        return helper(nums,paths,target,0);
        
    }
    bool helper(vector<int>& nums, vector<int>& paths, int target, int k) {
        if (k >= nums.size()) {
            for (auto path : paths) {
                if (path != target) return false;
            }
            return true;
        }
        for (int j = k; j < nums.size(); j++) {
            for (int i = 0; i < paths.size(); i++) {
                if (paths[i] + nums[j]>target) continue;
                paths[i] += nums[j];
                if (helper(nums, paths, target, j + 1)) return true;
                paths[i] -= nums[j];
            }
        }
        return false;
    }
};
```