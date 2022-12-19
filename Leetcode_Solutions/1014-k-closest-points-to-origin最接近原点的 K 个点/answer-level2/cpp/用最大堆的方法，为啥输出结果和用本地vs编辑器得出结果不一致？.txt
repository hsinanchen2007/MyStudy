
class Solution {
public:
	typedef pair<int, int> pT;
	struct cmp
	{
		bool operator()(const pT &left, const pT &right)const
		{
			return left.second<right.second;//最大堆
		}
	};
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		priority_queue<pT, vector<pT>, cmp> qMax;
		for (auto i : points)
		{
			pT point(i[0], i[1]);
			if (qMax.size()<K) {
				qMax.push(point);
			}
			else if ((qMax.top().first*qMax.top().first + qMax.top().second*qMax.top().second)>(point.first*point.first + point.second*point.second))
			{
				qMax.pop();
				qMax.push(point);
			}
		}
		vector<int> pDouble(2, 0);
		vector<vector<int>> ret(qMax.size(), pDouble);

		while (!qMax.empty())
		{
			ret[qMax.size() - 1][0] = qMax.top().first;
			ret[qMax.size() - 1][1] = qMax.top().second;
			qMax.pop();
		}
		return ret;
	}
};
