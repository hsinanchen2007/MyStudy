### 解题思路
- 注意到题目中矩阵的范围，`m`和`n`最大为100，因此可以建立一个数组，数组的下标来表示战士数量
- 可能有两行的军人数量相等，因此数组中的每一行用一个数组`vector`来存储对应的索引
- 二分查找获取到每行中1的个数，标准的upper_bound模板。以1的个数作为数组索引，存储行索引。
- 按照索引从小到大遍历该数组，获取到其中存储的行索引值即可

### 代码

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> record[101];
		vector<int> ans;
		for(int i=0;i<mat.size();i++)
		{
			int soldier = binarysearch(mat[i]);
			record[soldier].push_back(i);
		}
		for(int i=0;i<100;i++)
		{
			if(record[i].size())
			{
				for(auto idx:record[i])
				{
					ans.push_back(idx);
					if (ans.size() == k)return ans;
				}
			}
		}
		return {};
    }
private:
	int binarysearch(vector<int>& v)
	{
		int l = 0, r = v.size();
		while(l<r)
		{
			int mid = (l + r) / 2;
			if (v[mid] > 0)l = mid + 1;
			else r = mid;
		}
		return l;
	}
};
```