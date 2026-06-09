/*
给出一个区间的集合，请合并所有重叠的区间
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		int left = 0; int right = 0;
		vector<vector<int>> out;
		for (int i = 0; i < intervals.size();)
		{
			left = i;
			int j = i + 1;
			bool flag = false;
			int maxr = intervals[i][1];
			int minr = intervals[i][0];
			while (j<intervals.size()&&intervals[j][0]<=maxr)
			{
				maxr = max(maxr, intervals[j][1]);
				minr = min(minr, intervals[j][0]);
				j++;
				flag = true;
			}
			if (flag)
			{
				vector<int> x{minr,maxr};
				out.push_back(x);
				i = j;
			}
			else
			{
				vector<int> x{ intervals[i][0],intervals[i][1] };
				out.push_back(x);
				i++;
			}
		}
		return out;
	}
};

int main() {
	vector<int> a1{ 1,3 };
	vector<int> a2{ 0,2 };
	vector<int> a3{ 2,3 };
	vector<int> a4{ 4,6 };
	vector<int> a5{ 4,5 };
	vector<int> a6{ 5,5 };

	vector<vector<int>> in;
	in.push_back(a1);
	in.push_back(a3);
	in.push_back(a2);
	in.push_back(a4);
	in.push_back(a5);
	in.push_back(a6);
	Solution s;
	vector<vector<int>> out;
	out = s.merge(in);
	for (int i = 0; i < out.size(); i++)
	{
		for (int j = 0; j < out[0].size(); j++)
		{
			cout << out[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
