执行用时 :4 ms, 在所有 C++ 提交中击败了93.67%的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	vector<string> fizzBuzz(int n)
	{
		vector<string> res;
		for (int i = 1; i <= n; ++i)
		{
			if (i % 3 == 0 && i % 5 == 0)
				res.push_back("FizzBuzz");
			else
				if (i % 3 == 0)
					res.push_back("Fizz");
				else
					if (i % 5 == 0)
						res.push_back("Buzz");
					else
						res.push_back(to_string(i));
		}
		return res;

	}
};
```