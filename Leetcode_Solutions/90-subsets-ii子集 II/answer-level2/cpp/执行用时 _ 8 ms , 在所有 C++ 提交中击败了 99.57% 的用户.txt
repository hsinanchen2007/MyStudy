```
class Solution {
private:
	vector<int> curV;
	set<vector<int>> se;
public:
	void dfs(vector<int>&nums,int k,int n,int m)
	{
		if(k>0 && k>=nums.size()) return;
		
		if(curV.size()==n)
		{
				vector<int> v = curV;
				sort(v.begin(),v.end());
				se.insert(v);
		}

		
		for(int i=k+1;i<nums.size();i++){
			curV.push_back(nums[i]);
			dfs(nums,i,n,m-1);
			curV.pop_back();
		}
		
		
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int>> vv = {{}};
    	
    	if(nums.size()<=0) return vv;
    	
    	for(int i=1;i<=nums.size();i++)
        dfs(nums,-1,i,i);
  
		
		for(auto it=se.begin();it!=se.end();it++)
        vv.push_back(*it);
        
        return vv;
    }
};
```
