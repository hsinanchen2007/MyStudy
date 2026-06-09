在《挑战程序设计竞赛》中见过这道题。。。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(!n) return 0;
        int a[n];
        fill(a,a+n,INT_MAX);
        for(int i=0;i<n;++i){
            *lower_bound(a,a+n,nums[i])=nums[i];
        }
        int ans=lower_bound(a,a+n,INT_MAX)-a;
        return ans;
    }
};
```
