### 解题思路
1、判断2个区间重叠的依据：【A,B】.【C,D】
（1）B在CD之间B>=C && B<=D 
重叠的结果:MIN(A,C),D
（2）A在CD之间。A>=C, A<=D
重叠的结果： C,MAX(B,D)
（3）C在AB之间A<=C && B>=C
重叠的结果:MIN(A,C),MAX(B,D)
（4）D在AB之间A<=D && B>=D
重叠的结果:MIN(A,C),MAX(B,D)
2、把所有区间排序后，重叠区间相邻，这样第一批重叠处理完，紧接着处理第二批重叠部分，不存在第二批及之后的部分有可被第一批区间重叠的。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int> > res;
		if (intervals.empty())
			return res;
        auto cmp = [](vector<int>&lhd, vector<int>&rhd) { return lhd.at(0) < rhd.at(0); };
		sort(intervals.begin(), intervals.end(), cmp);
        int j = 0;
		res.push_back(intervals.at(0));
		for (int i = 1; i < intervals.size(); i++)
		{
			int &b = res[j][1];
			int &a = res[j][0];
			int c = intervals[i][0];
			int d = intervals[i][1];
			if (b >=c  && b <= d 
				|| a >= c && a <= d 
				|| a <= c && b >= c 
				|| d >= a && d <= b) 
			{
				if (a > c)
					a = c;
				if (b < d)
					b = d;
			}
			else
			{
				res.push_back(intervals.at(i));
				j++;
			}
		}
		
		return res;
	}
};
```