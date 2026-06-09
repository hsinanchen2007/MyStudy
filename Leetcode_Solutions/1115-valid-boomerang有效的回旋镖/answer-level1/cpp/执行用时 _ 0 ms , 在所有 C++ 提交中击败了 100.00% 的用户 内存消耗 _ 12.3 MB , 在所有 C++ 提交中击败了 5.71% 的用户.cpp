### 解题思路
首先分母不能为0，其次各个坐标不相等，再斜率不等（注意整除时用double），则true。

### 代码

```cpp
class Solution {
public:
   bool isBoomerang(vector<vector<int>>& points) {
	bool f = 0;
	double k1 = 0, k2 = 0;
	if (points[0][1] - points[1][1] == 0)
	{
		k1 = INT_MAX;
	}

	if (points[1][1] - points[2][1] == 0)
	{
		k2 = INT_MAX;
	}
	if (points[0] != points[1] && points[0] != points[2] && points[2] != points[1])
	{
		if (k1 != INT_MAX) k1 = (double)(points[0][0] - points[1][0]) / (points[0][1] - points[1][1]);
		if (k2 != INT_MAX) k2 = (double)(points[1][0] - points[2][0]) / (points[1][1] - points[2][1]);
		if (k1 != k2) f = 1;
	}
	return f;
}
};
```