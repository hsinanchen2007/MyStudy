### 解题思路
直接用栈写。先二分查找插入位置，再一个个入栈，如果合并就将原先区间出栈，再将合并区间入栈。
![image.png](https://pic.leetcode-cn.com/8c110111b16d4f38c644abdafddb1105c322667a9fbab7fdcf7b277e3b3b4cef-image.png)


### 代码

```cpp
class Solution {
public:
struct interval
{
	vector<int>inter;
	friend bool operator<(const interval&a, const interval&b)
	{
		if(a.inter[0] < b.inter[0])
		return true;
		if (a.inter[0] == b.inter[0])
			return a.inter[1] < b.inter[1];
		else return false;
	}
	bool operator<(const interval&b)
	{
		if (inter[0] < b.inter[0])
			return true;
		if (inter[0] == b.inter[0])
			return inter[1] < b.inter[1];
		else return false;
	}
};
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval_1) {
    if(intervals.size()==0)
    {
        vector<vector<int>>res;
        res.push_back(newInterval_1);
        return res;
    }
    if(newInterval_1.size()==0)
    return intervals;
    int size = intervals.size();
	interval*arr = new interval[size];
	interval newInter;
	newInter.inter = newInterval_1;
	for (int i = 0; i < size; i++)
		arr[i].inter = intervals[i];
	int index=lower_bound(arr, arr + size, newInter)-arr;
	vector<vector<int>>st;
	vector<int>temp = { 0,0 };
	for (int i = 0; i <=index-1; i++)
	{
		if (st.size() == 0)
			st.push_back(intervals[i]);
		else
		{
			if (st.back()[1] >= intervals[i][0])
			{
				temp[0] = st.back()[0];
				temp[1] = st.back()[1] > intervals[i][1] ? st.back()[1] : intervals[i][1];
				st.pop_back();
				st.push_back(temp);
			}
			else st.push_back(intervals[i]);
		}
	}
    if(st.size()!=0)
    if (st.back()[1] >= newInterval_1[0])
	{
		temp[0] = st.back()[0];
		temp[1] = st.back()[1] > newInterval_1[1] ? st.back()[1] : newInterval_1[1];
		st.pop_back();
		st.push_back(temp);
	}
	else st.push_back(newInterval_1);
    else st.push_back(newInterval_1);
    for (int i = index; i <size; i++)
	{
		if (st.size() == 0)
			st.push_back(intervals[i]);
		else
		{
			if (st.back()[1] >= intervals[i][0])
			{
				temp[0] = st.back()[0];
				temp[1] = st.back()[1] > intervals[i][1] ? st.back()[1] : intervals[i][1];
				st.pop_back();
				st.push_back(temp);
			}
			else st.push_back(intervals[i]);
		}
	}
    return st;
    }
};
```