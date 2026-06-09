看大家都写得很复杂的样子，又是map又是set的，感觉我自己的做法更好理解一点。先对tickets进行排序，使得对于相同的起始点，落地点按照字典序排列。然后就是回溯了，用一个used数组记录每个机票是否使用。回溯的终止条件是当前ret.size() == tickets.size() + 1，ret记录了沿途的地点名字。对于每一个以cur为起点的机票进行递归遍历，注意used的设置。

```
class Solution {
public:

	bool dfs(string cur, vector<vector<string>> &tickets, vector<string> &ret,
		vector<bool> &used)
	{
		ret.push_back(cur);
		if (ret.size() == tickets.size() + 1)
			return true;
		for (int i = 0; i < tickets.size(); ++i)
		{
			if (!used[i] && tickets[i][0] == cur)
			{
				used[i] = true;
				if (dfs(tickets[i][1], tickets, ret, used))
					return true;
				used[i] = false;
			}
		}
		ret.pop_back();
		return false;
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> result;
		vector<bool> used(tickets.size(), false);
		std::sort(tickets.begin(), tickets.end(),
			[](const vector<string> &n1, const vector<string> &n2)
		{
			if (n1[0] == n2[0])
				return n1[1] < n2[1];
			else
				return n1[0] < n2[0];
		});

		dfs("JFK", tickets, result, used);
		return result;
	}
};
```
