
C++:

```
class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int T = 0;
		for (int i = 0; i < points.size() - 1;i++) {
			int a = min(abs(points[i][0] - points[i+1][0]), abs(points[i][1] - points[i+1][1]));
			int b = abs(max(abs(points[i+1][0] - points[i][0]), abs(points[i+1][1] - points[i][1])) - a);
			T += (a + b);	
		}
        return T;
	}
};
```

python:
```
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def time(l1, l2):
            a = min(abs(l2[0] - l1[0]), abs(l2[1] - l1[1]))
            b = abs(max(abs(l2[0] - l1[0]), abs(l2[1] - l1[1])) - a);
            return a + b

        T = 0
        for i in range(len(points) - 1):
            t = time(points[i], points[i+1])
            T += t
        return T

```

