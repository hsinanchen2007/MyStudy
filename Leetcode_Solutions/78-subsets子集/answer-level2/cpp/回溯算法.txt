```
class Solution {
public:
    vector<vector<int>>res;
       void fun(vector<int>&nums,vector<int>&temp,int start,int n){
            if(temp.size()<=n)
                res.push_back(temp);
        for(int i=start;i<n;i++){
            temp.push_back(nums[i]);
            fun(nums,temp,start+1,n);
            temp.pop_back();
            start++;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        fun(nums,temp,0,n);
        return res;
    }
};
```
