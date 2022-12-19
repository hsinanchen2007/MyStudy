```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        map<int,vector<int>>p;
        for(int i=0;i<m;i++){
	       int sum=accumulate(mat[i].begin(),mat[i].end(),0);
	       p[sum].push_back(i);
	    }
        vector<int>ans;
        for(auto a:p)
        {
            for(auto c:a.second)
                {
                    ans.push_back(c);
                    k--;
                    if(k<=0) return ans;
                 }
        }
        return ans;
    }
};
```
