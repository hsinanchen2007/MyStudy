class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>vvec;
        vector<int>vec;
        vvec.push_back(vec);
        int start=0;
        int end=nums.size();
        help(vvec,vec,start,end,nums);
        return vvec;
    }
    void help(vector<vector<int>>&vvec,vector<int>&vec,int start,int end,vector<int>&nums){
        if(start==end)return;
        int val=-1;
        for(start;start<end;start++){
            if(start!=0&&nums[start]==val)continue;
            else{
                val=nums[start];
                vec.push_back(nums[start]);
                vvec.push_back(vec);
                val=nums[start];
                help(vvec,vec,start+1,end,nums);
                vec.pop_back();
            }
        }
    }
};