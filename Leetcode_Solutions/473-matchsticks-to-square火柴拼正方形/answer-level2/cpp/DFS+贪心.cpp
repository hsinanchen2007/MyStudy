DFS的时候从大到小遍历（贪心），这样不需要回溯
```
class Solution {
public:
    bool DFS(vector<int>&nums,vector<bool>&vis,int i,int a,int cur){
        vis[i]=true;
        cur+=nums[i];
        if(cur==a) return true;
        for(int j=i-1;j>=0;j--) if(!vis[j]&&nums[j]+cur<=a){
            if(DFS(nums,vis,j,a,cur)) return true;
            vis[j]=false;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size()<4) return false;
        sort(nums.begin(),nums.end());
        vector<bool>vis(nums.size(),false);
        int a=0,i=nums.size()-1;
        for(int num:nums) a+=num;
        if(a%4) return false;
        a/=4;
        if(nums.back()>a) return false;
        for(int j=0;j<4;j++){
            while(vis[i]) i--;
            if(!DFS(nums,vis,i,a,0)) return false;
        }
        return true;
    }
};
```