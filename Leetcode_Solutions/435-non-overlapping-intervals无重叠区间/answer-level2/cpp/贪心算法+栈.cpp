### 解题思路


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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        return 0;
    int sz = intervals.size();
	interval*arr = new interval[sz];
	for (int i = 0; i < sz; i++)
	{
		arr[i].a = intervals[i][0];
		arr[i].b = intervals[i][1];
	}
	sort(arr, arr + sz);
	stack<interval>st;
	st.push(arr[0]);
	int res = 0;
	for (int i = 1; i < sz; i++)
	{
		if (st.top().b<= arr[i].a)
		{
			st.push(arr[i]);
		}
		else
		{
			if (st.top().b >= arr[i].b)
				st.pop(), st.push(arr[i]);
		}
	}
	res = sz - st.size();
    return res;
    }
};
```