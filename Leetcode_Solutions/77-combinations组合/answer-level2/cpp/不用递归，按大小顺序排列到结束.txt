### 解题思路
用时8ms，战胜98.42%，内存9.1MB,战胜100%。
不断更新单个输入用例tmp，从第一位往后更新，后一位必须大于前一位，第i位最大能到n - k + i + 1，当第i位更新到顶时，返回更新第i-1位。当第0位更新到顶时，输出结果。

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> tmp(k);
		vector<vector<int>> res;
        if(k > n)
            return res;
        if(k == n)
        {
            for(int i = 1; i <= n; i++)
                tmp[i - 1] = i;
            res.push_back(tmp);
            return res;
        }

		tmp[0] = 1;
		int i = 0;
		while (tmp[0] <= n - k + 1)
		{
			if (i && tmp[i] < tmp[i - 1] || tmp[i] >= n - k + 1)
				tmp[i] = tmp[i - 1] + 1;
			if (i == k - 1)
			{
				while (tmp[i] <= n)
				{
					res.push_back(tmp);
					tmp[i]++;
				}
				while (i && tmp[i] >= n - k + i + 1)
					i--;
				tmp[i]++;
			}
			i++;
		}

		return res;
	}
};
```