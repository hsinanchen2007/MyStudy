### 解题思路
首先要发现有一个结论：若要删除一定数量的区间使得剩余区间互不相交，则气球总数-删除的数量的最少值=所需射箭的最小值。
![image.png](https://pic.leetcode-cn.com/0644721f07cb5c0c6acf1c67ba203c38a53df71caff86dbd10b684a5009c81b8-image.png)

### 代码

```cpp
class Solution {
public:
    struct interval
    {
	int a, b;
	friend bool operator<(const interval&a, const interval&b)
	{
		if (a.a < b.a)return true;
		else if (a.a == b.a)return a.b < b.b;
		else return false;
	}
    };
    int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size()<=0)return points.size();
   int sz = points.size();
	interval*arr = new interval[sz];
	for (int i = 0; i < sz; i++)
	{
		arr[i].a = points[i][0];
		arr[i].b = points[i][1];
	}
	sort(arr, arr + sz);
	int res = 0;
	stack<interval>st;
	st.push(arr[0]);
	for (int i = 1; i < sz; i++)
	{
		if (st.top().b < arr[i].a)
			st.push(arr[i]);
		else {
			if (st.top().b >= arr[i].b)
				st.pop(), st.push(arr[i]);
		}
	}
	return res=st.size();
    }
};
```