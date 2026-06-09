### 解题思路
其实和其他哥们的解差不多，就是归并，和***里的逆序对题目类似

### 代码

```cpp
class Solution
{
public:
	vector<int> res;

	vector<int> countSmaller(vector<int>& nums)
	{
		int n = nums.size();
		res = vector<int>(n, 0);
		if (n == 0)
			return res;
		vector<pair<int, int>> sortnums(n);

		for (int i = 0; i < nums.size(); i++)
		{
			sortnums[i] = {nums[i], i};
		}
		mergeSort(sortnums, 0, n - 1);
		return res;
	}

	void mergeSort(vector<pair<int, int>>& sortnums, int l, int r)
	{
		if (l < r)
		{
			int mid = (r - l) / 2 + l;
			mergeSort(sortnums, l, mid);
			mergeSort(sortnums, mid + 1, r);
			merge(sortnums, l, mid, mid + 1, r);
		}
	}

	void merge(vector<pair<int, int>>& sortnums, int begin1, int end1, int begin2, int end2)
	{
		int k = 0;
		vector<pair<int, int>> tmp(end2 - begin1 + 1);
		int i = begin1;
		int j = begin2;
		while (i <= end1 && j <= end2)
		{
			if (sortnums[i].first <= sortnums[j].first)
			{
				res[sortnums[i].second] += (j - end1 - 1);
				tmp[k++] = sortnums[i++];
			}
			else
			{
				tmp[k++] = sortnums[j++];
			}
		}
		while (i <= end1)
		{
			res[sortnums[i].second] += (j - end1 - 1);
			tmp[k++] = sortnums[i++];
		}
		while (j <= end2)
		{
			tmp[k++] = sortnums[j++];
		}
		for (int i = begin1, j = 0; i <= end2; ++i, j++)
		{
			sortnums[i] = tmp[j];
		}
	}
};

```