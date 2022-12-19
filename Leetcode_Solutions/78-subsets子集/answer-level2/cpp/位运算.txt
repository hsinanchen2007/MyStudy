同 大力王 大佬的想法， 位运算即可

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int ALL = 1<<n;
        
        vector<vector<int>> ans;
        vector<int>ret;
        ret.clear();
        ans.clear();
        
        for(int i=0; i<ALL; i++){
            
            ret.clear();
            
            for(int j=0; j<n; j++){
                if( i & (1<<j) )
                {
                    //printf("%d %d\n",i,j);
                    ret.push_back(nums[j]);
                }
            }
            
            ans.push_back(ret);
        }
        
        return ans;
    }
};