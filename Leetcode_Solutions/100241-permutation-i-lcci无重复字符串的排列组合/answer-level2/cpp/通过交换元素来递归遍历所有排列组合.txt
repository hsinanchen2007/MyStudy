### 解题思路
第一层循环，将S的第一个元素分别和后面的元素交换，S的排列组合便转化为除第一个元素之后剩余元素的排列组合，后面层层递归，递归到最后一层的结果作为一个排列。每一次递归完毕后撤销之前的交换操作，作为回溯的核心

### 代码

```cpp
class Solution
{
public:
	vector<string> permutation(string S)
	{
		vector<string> res;

		backTrack(res, S, 0);
		return res;
	}

	void backTrack(vector<string> &res, string S, int begin)
	{
		if (begin == S.size())
		{
			res.push_back(S);       //只有到达最后一层再输出
		}
		for (int i = begin; i < S.size(); ++i)
		{
			swap(S[begin], S[i]);
			backTrack(res, S, begin + 1);
			swap(S[begin], S[i]);   //撤销之前的交换
		}
	}
};
```