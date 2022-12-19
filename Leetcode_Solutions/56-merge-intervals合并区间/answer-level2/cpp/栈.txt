### 解题思路
先对区间下界排序，再把vector<vector<int>>当栈使用以合并。

### 代码

```cpp
class Solution {
public:
struct interval
{
	vector<int>inter;
	friend bool operator<(const interval&a, const interval&b)
	{
		return a.inter[0] < b.inter[0];
	}
	bool operator<(const interval&b)
	{
		return inter[0] < b.inter[0];
	}
};
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    vector<int>temp = { 0,0 };
	int size = intervals.size();
    if(size<=1)
    return intervals;
	interval*arr = new interval[size];
	for (int i = 0; i < size; i++)
		arr[i].inter = intervals[i];
	sort(arr, arr + size);
	for (int i = 0; i < size; i++)
		intervals[i]=arr[i].inter;
	vector<vector<int>>st;
	st.push_back(arr[0].inter);
	for (int i = 1; i < size; i++)
	{
		if (arr[i].inter[0] <= st.back()[1])
		{
			temp[0] = st.back()[0];
			temp[1] = arr[i].inter[1] > st.back()[1] ? arr[i].inter[1] : st.back()[1];
			st.pop_back();
			st.push_back(temp);
		}
		else st.push_back(intervals[i]);
	}
    return st;
    }
};
```