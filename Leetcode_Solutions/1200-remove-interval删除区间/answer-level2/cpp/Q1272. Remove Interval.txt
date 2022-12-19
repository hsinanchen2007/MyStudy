模拟，分情况讨论即可。扫描区间列表
1. 如果区间`interval`和要删除的区间`toBeRemoved`不相交，则将区间`interval`添加到剩余区间列表`vecAns`；
2. 如果要删除的区间`toBeRemoved`的左边界大于区间`interval`的左边界，则添加区间`[interval.left, toBeRemoved.left)`；
3. 如果要删除的区间`toBeRemoved`的右边界小于区间`interval`的右边界，则添加区间`[toBeRemoved.right, interval.right)`。
```
class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
		vector<vector<int>> vecAns;
		vector<vector<int>>::iterator it = intervals.begin();
		for (; it != intervals.end(); ++it) {
			vector<int> interval = (*it);
			if (interval[1] <= toBeRemoved[0] ||
				interval[0] >= toBeRemoved[1])
			{
				vecAns.push_back(interval);
				continue;
			}

			if (toBeRemoved[0] <= interval[0] &&
				toBeRemoved[1] >= interval[1])
				continue;

			if (toBeRemoved[0] > interval[0]) {
				vector<int> leftPart;
				leftPart.push_back(interval[0]);
				leftPart.push_back(toBeRemoved[0]);
				vecAns.push_back(leftPart);
			}

			if (toBeRemoved[1] < interval[1]) {
				vector<int> rightPart;
				rightPart.push_back(toBeRemoved[1]);
				rightPart.push_back(interval[1]);
				vecAns.push_back(rightPart);
			}
		}

		return vecAns;
	}
};
```