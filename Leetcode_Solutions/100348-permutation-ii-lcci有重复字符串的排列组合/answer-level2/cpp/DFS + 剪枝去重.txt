### 解题思路
在“无重复字符串排列组合”题目代码回溯基础上加上条件判断去重即可，方法见代码注释

### 代码

```cpp
class Solution
{
public:
	vector<string> permutation(string S)
	{
		vector<string> res;
		sort(S.begin(), S.end());   //先排列，使得重复字符相邻，便于后面去重
		backTrack(res, S, 0);
		return res;
	}

	void backTrack(vector<string> &res, string S, int begin)
	{
		if (begin == S.size())
		{
			res.push_back(S);
		}
		for (int i = begin; i < S.size(); ++i)
		{
            /*因为首次交换是i == begin，S[i]与自身交换
            因此考虑两种重复情况的去除
            1.S[i] == S[i-1]
            2.S[i] == S[begin]*/
			if (i > begin && (S[i] == S[i - 1] || S[i] == S[begin]))
			{
				continue;
			}
			else
			{
				swap(S[begin], S[i]);
				backTrack(res, S, begin + 1);	//DFS
				swap(S[begin], S[i]);
			}
		}
	}
};
```