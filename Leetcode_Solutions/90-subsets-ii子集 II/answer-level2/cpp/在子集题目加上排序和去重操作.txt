class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size()==0){return vector<vector<int>>{};}
                vector<vector<int>>q;
        for(int i=0;i<nums.size();i++){
            q.push_back(vector<int>{nums[i]});
            int k=q.size()-1;
            for(int j=0;j<k;j++){
                vector<int>temp=q[j];
                temp.push_back(nums[i]); 
                sort(temp.begin(),temp.end());
                q.push_back(temp);
            }
        }
        q.push_back(vector<int>{});
        sort(q.begin(),q.end());
        q.erase(unique(q.begin(),q.end()),q.end());
        return q;
    }
};