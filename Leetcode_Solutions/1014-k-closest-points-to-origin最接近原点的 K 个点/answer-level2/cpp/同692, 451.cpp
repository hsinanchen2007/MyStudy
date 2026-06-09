### 解题思路
执行用时 :336 ms, 在所有 C++ 提交中击败了44.25% 的用户
内存消耗 :69.1 MB, 在所有 C++ 提交中击败了16.38%的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	map<vector<int>, double> dist;
    	for(size_t i=0;i<points.size();++i){
    		dist[points[i]] = pow(points[i][0],2) + pow(points[i][1], 2);
    	}
    	vector<pair<vector<int>, double>> p_dist(dist.begin(), dist.end());
    	std::sort(p_dist.begin(), p_dist.end(), [](const pair<vector<int>, double>& l, const pair<vector<int>, double>& r){
    		return l.second < r.second;
    	});

    	vector<vector<int>> p_kClosest;
    	for(size_t i=0;i<static_cast<size_t>(K);++i){
    		p_kClosest.push_back(p_dist[i].first);
    	}
    	return p_kClosest;
    }
};
```