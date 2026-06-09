class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tem;
        dfs(ans,tem,1,0,k,n);
        return ans;
    }

private:
    void dfs(vector<vector<int>> & ans,vector<int> & tem,int start, int sum,int k ,int n){
        if(sum > n ) return ;
        if(tem.size() >= k){
            if(sum == n && tem.size() == k){
                ans.push_back(tem);
            }
            return ;
        }
        for(int i = start;i<=9;i++){
            tem.push_back(i);
            dfs(ans,tem,i+1,sum+i,k,n);
            tem.pop_back();

        }
    }
};