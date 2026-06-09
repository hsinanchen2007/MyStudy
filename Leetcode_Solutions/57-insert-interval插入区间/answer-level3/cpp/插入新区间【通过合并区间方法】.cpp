### 解题思路
此处撰写解题思路
总思路：通过合并区间的方式来输出结果
1、找出新插入区间的位置。
2、如果是第0个，则放置到输出开头。
3、如果是中间位置，则在合并区间时，增加一个判断，是否到新区间位置，到达则合并此区间。
4、如果新区间，是最后的，则把其放置到最后。
上面思路针对2,3步骤可以进行优化，因为既然是有序的，则可以把前面的部分进行直接拷贝。
### 代码

```cpp
class Solution {
	void merge(vector<vector<int>>&res, const vector<int>&cd )
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
			res.push_back(cd);
	}
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> res;
		int firstDayuPos = -1;
		for (int i = 0; i < intervals.size(); i++)
			if (intervals[i][0] > newInterval[0])
			{
				firstDayuPos = i;
				break;
			}
		if (firstDayuPos == -1)
		{
			intervals.push_back(newInterval);
		}
		if (intervals.empty())
		{
			res.push_back(newInterval);
			return res;
		}

		int pos = -1;
		if (firstDayuPos == 0)
			res.push_back(newInterval);
		else
		{
			res.push_back(intervals[0]);
			pos = 0;
		}

		for (int j = pos + 1; j < intervals.size(); j++)
		{//[a,b][c,d]
			if ( firstDayuPos != 0  && j== firstDayuPos)
			{
				merge(res, newInterval);
			}
			merge(res, intervals[j]);
		}
		return res;
	}

};

```