```
class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		unordered_map<double, int> m;
		int n = points.size(),res = 0;
		if (n <= 2)
			return n;
		double k;
		for (int i = 0; i < n; i++) {
			m.clear();
			int num = 0, p = 0;
			for (int j = i+1; j < n; j++) {
                if(points[j] == points[i]){
                    ++num;
                    continue;
                }
				if (points[i][1] == points[j][1])
					k = INT_MIN;
				else
					k = double((points[i][0]-points[j][0]))/double((points[i][1]-points[j][1]));

				++m[k];
				p = max(p, m[k]);
			}
			res = max(p+num,res);
		}
		return res+1;
	}
};
```
