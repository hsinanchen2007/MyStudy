
执行用时 :856 ms, 在所有 C++ 提交中击败了5.14%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了85.37%的用户
### 代码

```cpp
class Solution {
public:
	bool isprimes(int num)
	{
		if (num == 0 || num == 1)
			return false;
		if (num == 2)
			return true;
		//int flag = 0;
		for (int i = 2; i <= sqrt(num); ++i)//不开方会超时
		{
			if (num % i == 0)
				return false;
			else
				continue;
		}
		return true;
	}
public:
	int countPrimes(int n)
	{
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (isprimes(i))
				count++;
		}
		return count;
	}
};
```