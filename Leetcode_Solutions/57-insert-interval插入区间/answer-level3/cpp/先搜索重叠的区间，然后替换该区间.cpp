虽然不是很快，但是自我感觉比较优雅……
```
class Solution {
public:
	int findFirst(vector<vector<int>>& intervals, int l, int r, int first)
	//返回包含first的区间下标，如果没有就返回第一个大于first的区间下标
	{
		int mid = (l + r) >> 1;
		if (intervals[mid][0] <= first && intervals[mid][1] >= first)
			return mid;
		if (intervals[mid][0] > first)
		{
			if (mid == l)
				return l;
			else
			{
				if (intervals[mid - 1][1] >= first)
					return findFirst(intervals, l, mid - 1, first);
				else
					return mid;
			}
		}
		else
			return findFirst(intervals, mid + 1, r, first);
	}
	int findLast(vector<vector<int>>& intervals, int l, int r, int last)
	//返回包含last的区间下标，如果没有就返回最后一个小于last的区间下标
	{
		int mid = (l + r) >> 1;
		if (intervals[mid][0] <= last && intervals[mid][1] >= last)
			return mid;
		if (intervals[mid][1] < last)
		{
			if (mid == r)
				return r;
			else
			{
				if (intervals[mid + 1][0] <= last)
					return findLast(intervals, mid + 1, r, last);
				else
					return mid;
			}
		}
		else
			return findLast(intervals, l, mid - 1, last);
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
		if(n==0)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		int first = newInterval[0], last = newInterval[1];
		if (last < intervals[0][0])
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		else if (first > intervals[n - 1][1])
		{
			intervals.insert(intervals.end(), newInterval);
			return intervals;
		}
		else
		{
			int firstIndex = findFirst(intervals, 0, n - 1, first);
			int lastIndex = findLast(intervals, 0, n - 1, last);
			if (firstIndex > lastIndex)//直接可以插入intervals里面
			{
				intervals.insert(intervals.begin() + firstIndex, newInterval);
				return intervals;
			}
			else if (firstIndex == lastIndex)
			{
				if (intervals[firstIndex][0] > first)
					intervals[firstIndex][0] = first;
				if (intervals[firstIndex][1] < last)
					intervals[firstIndex][1] = last;
				return intervals;
			}
			else
			{
				if (intervals[firstIndex][0] < first)
					first = intervals[firstIndex][0];
				if (intervals[lastIndex][1] > last)
					last = intervals[lastIndex][1];
				intervals.erase(intervals.begin() + firstIndex, intervals.begin() + lastIndex + 1);
				intervals.insert(intervals.begin() + firstIndex, vector<int>({ first,last }));
				return intervals;
			}
		}
	}
};
```
