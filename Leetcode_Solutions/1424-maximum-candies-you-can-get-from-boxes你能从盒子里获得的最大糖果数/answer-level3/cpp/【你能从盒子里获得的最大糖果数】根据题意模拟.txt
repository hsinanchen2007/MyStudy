### 思路
1. 按照题意模拟即可。
2. 使用`vector<int> haveStatus(status.size(), 0);`表示已经拿到手的盒子。
3. 使用`vector<int> keyStatus(status.size(), 0);`表示已经取得的钥匙。
4. 然后就从拿到手的盒子遍历，判断是否打开的，或者有钥匙。
    41. 如果能打开，执行打开操作。
    42. 拿糖果
    43. 拿盒子
    44. 拿钥匙
5. 一直到没有盒子可以打开为止。

### 答题
```C++
vector<int> getHaveBoxes(vector<int>& haveStatus)
{
	vector<int> ret;
	for (auto i = 0; i < haveStatus.size(); i++)
	{
		if (haveStatus[i] == 1)
		{
			ret.push_back(i);
		}
	}
	return ret;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
	vector<int> haveStatus(status.size(), 0);
	for (auto n : initialBoxes) haveStatus[n] = 1;
	vector<int> keyStatus(status.size(), 0);

	int ans = 0;

	bool flag = true;
	while (flag)
	{
		flag = false;

		auto have = getHaveBoxes(haveStatus);
		if (have.empty()) break;

		for (auto i : have)
		{
			if (status[i] == 1 || keyStatus[i] == 1)
			{
				flag = true;
				haveStatus[i] = 2;

				ans += candies[i];
				for (auto k : keys[i])
				{
					keyStatus[k] = 1;
				}
				for (auto c : containedBoxes[i])
				{
					haveStatus[c] = 1;
				}
			}
		}
	}
	return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

