### 思路
1. 将所有组合按照顺序排列
2. 找出排列之间的变化关系
> [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
3. 通过一个结果转化到下一个结果

### 答题
```C++
bool getNext(vector<int>& a, int n)
{
	int _max = n;
	for (size_t i = a.size() - 1; i < a.size(); i--)
	{
		if (a[i] < _max)
		{
			a[i]++;
			for (size_t j = i + 1; j < a.size(); j++)
			{
				a[j] = a[j - 1] + 1;
			}
			return true;
		}
		_max--;
	}
	return false;
}

vector<vector<int>> combine(int n, int k) 
{
	vector<int> a;
	for (size_t i = 0; i < k; i++) a.push_back(1 + i);

	vector<vector<int>> ans;
	do
	{
		ans.push_back(a);
	} while (getNext(a, n));

	return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

