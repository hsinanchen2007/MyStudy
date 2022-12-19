### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		unordered_map<double, int> map;//first为斜率（注意斜率必须为浮点数），second为num
		int n = points.size();
		if (n <= 2)
			return n;
		int m = 0, num = 0;
		double k;
		for (int i = 0; i < n; i++) {
			map.clear();//每个点处理完后，要清除map。
			num = 0;//
			//先找出有几个同一位置的点
			for (int j = 0; j < n; j++) {
				if (i != j) {
					if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
						num += 1;
				}
			}
			for (int j = 0; j < n; j++) {
				if (i != j && (points[i][0] != points[j][0] || points[i][1] != points[j][1])) {
					if (points[i][1] - points[j][1] == 0)//除数为0的情况
						k = INT_MIN;
					else
						k = double((points[i][0] - points[j][0])) / double((points[i][1] - points[j][1]));
					if (map.count(k)) {
						map[k] += 1;
						m = max(m, map[k]);
					}
					else {
						map.insert({ k,2 + num });//2表示point[i]和point[j]
						m = max(2, m);
					}
				}
			}
			m = max(m, num + 1);//如果同一位置的最多，那还应该加上本身
		}
		return m;
	}
};
```