本题的第一关键字是行和，第二关键字是行id，两者都是按照升序排列，因此可以直接用方法一：自己重写排序规则，这种方法的适用性更广。
方法二：由于两者刚好都是升序排列，可以直接用vector<pair<int,int>>x 排序
```
class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b){
    if(a[0]<b[0])return true;
    if(a[0]>b[0])return false;
    if(a[0]==b[0]){
        if(a[1]<b[1])return true;
        else return false;
    }
    return true;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> x(m);
        for(int i=0;i<m;i++){
	       int sum=accumulate(mat[i].begin(),mat[i].end(),0);
	       x[i].push_back(sum);
           x[i].push_back(i);
	    }
        sort(x.begin(),x.end(),cmp);

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(x[i][1]);
        }
        return ans;
    }
};
```
方法二：
   ```
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	int m=mat.size(),n=mat[0].size();
	vector<pair<int,int>> x;
	for(int i=0;i<m;i++){
	   int sum=accumulate(mat[i].begin(),mat[i].end(),0);
	   x.emplace_back(sum,i);
	}
    sort(x.begin(),x.end());
	vector<int>ans;
	for(int i=0;i<k;i++){
		ans.push_back(x[i].second);
	}
	return ans;
}
```
