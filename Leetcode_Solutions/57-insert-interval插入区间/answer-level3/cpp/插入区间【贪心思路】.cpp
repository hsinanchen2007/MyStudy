### 解题思路
参考官方贪心思路实现
0、由于输入区间已经是排序
1、新区间开始前的push到输出，记录下其位置
2、把新区间和输出的最后一个合并区间。
3、把记录位置之后的区间和输出的最后一个合并区间。
### 代码

```cpp
class Solution {
	void merge(vector<vector<int>>&res, const vector<int>&cd)
	{
		if (res.empty())
			res.emplace_back(cd);
		else
		{
			int k = res.size() - 1;
			int &a = res[k][0];
			int &b = res[k][1];
			int c = cd[0];
			int d = cd[1];
			if (b >= c && b <= d
				|| c >= a && c <= b)
			{
				b = std::max(b, d);
			}
			else
				res.emplace_back(cd);
		}

	}
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int firstDayuPos = -1;
		for (int i = 0; i < intervals.size(); i++)
		{
			if (intervals[i][0] >= newInterval[0])
			{
				break;
			}
			else
			{
				firstDayuPos = i;
				res.emplace_back(intervals[i]);
			}
		}
		merge(res,newInterval);
		for (int i = firstDayuPos + 1; i < intervals.size(); i++)
		{
			merge(res, intervals[i]);
		}
		return res;
	}

};
```