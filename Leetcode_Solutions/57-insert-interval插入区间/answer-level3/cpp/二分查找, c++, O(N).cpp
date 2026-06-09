二分搜索插入位置, 再按照56题的插入就好了
![tmp2.png](https://pic.leetcode-cn.com/6d5128e601df318fc6f26618e2bef5f7bbbeb8ba39c18a1e7e786afbd680bf46-tmp2.png)
![tmp3.png](https://pic.leetcode-cn.com/7b66b97fe4126e6d75f0d29dbbec5386785988b7647ffb18f1be305a10637bb2-tmp3.png)
![tmp1.png](https://pic.leetcode-cn.com/45e800ed5b59b0fe4e61de2b2b826b7801d2d01bd2d157e7c5d3ba72e2ffcb33-tmp1.png)


```
#define ll long long int
#include <vector>
#include <queue>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#define abs(x) (x > 0 ? x : -x)
#define MAXN (302)
using namespace std;
#define debug
typedef vector<vector<int> > vvi;
bool cmp(vector<int>&x, vector<int>& y) { return x[0] < y[0]; }

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& vv, vector<int>& x) {
		vvi ret;
		if(vv.empty() && x.empty()) return ret;
        if(vv.empty() && !x.empty()) return {x};
		int lef = 0, rig = vv.size()-1, mid, idx = -1;
		while(lef <= rig) { //先二分到x相对与数组vv的位置,再分情况讨论即可
			mid = (lef + rig) >> 1;
			if(vv[mid][0] <= x[0]) idx = mid, lef = mid + 1;
			else rig = mid - 1;
		}
		if(idx == -1) ret.push_back(x); //x在最前面的情况
		int i = 0, n = idx==(int)vv.size() ? vv.size()-1 : idx;
		for( ; i<=n; i++) {
			if(!i && ret.empty()) {
				ret.push_back(vv[i]);
			} else {
				vector<int>& lst = ret.back();
				if(lst[1] >= vv[i][0]) lst[1] = max(vv[i][1], lst[1]);
				else ret.push_back(vv[i]);
			}
		}
		if(idx != (int)vv.size()) { //x在中间的情况
			vector<int>& lst = ret.back();
			if(lst[1] >= x[0]) lst[1] = max(lst[1], x[1]);
			else ret.push_back(x);
		}
		n = vv.size();
		for( ; i<n; i++) {
			if(!i && ret.empty()) {
				ret.push_back(vv[i]);
			} else {
				vector<int>& lst = ret.back();
				if(lst[1] >= vv[i][0]) lst[1] = max(vv[i][1], lst[1]);
				else ret.push_back(vv[i]);
			}
		}
		if(idx == (int)vv.size()) { //x在最后一个的情况
			vector<int>& lst = ret.back();
			if(lst[1] >= x[0]) lst[1] = max(lst[1], x[1]);
			else ret.push_back(x);
		}
		return ret;
    }
};
#define debug
#ifdef debug22333333
int main(void) {
	freopen("test", "r", stdin);
	Solution s;
	vvi vv = {
		{1,3},{6,9}
	};
	vector<int> x = {
		{2, 5}
	};
	vvi ret = s.insert(vv, x);
	for(int i=0; i<(int)ret.size(); i++) {
		printf("%d %d\n", ret[i][0], ret[i][1]);
	}
	return 0;
}
#endif


```
