执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	bool isUgly(int num) 
	{
		if (num <= 0) return false;
		while (num > 1)
		{
			if (num % 2 == 0)
				num /= 2;
			else
				if (num % 3 == 0)
					num /= 3;
				else
					if (num % 5 == 0)
						num /= 5;
					else
						return false;
		}
		return true;
	}
};
```