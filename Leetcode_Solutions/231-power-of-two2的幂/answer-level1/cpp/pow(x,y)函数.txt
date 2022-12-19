执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 ：8.2 MB, 在所有 C++ 提交中击败了5.34%的用户

### 代码

```cpp
class Solution {
public:
	bool isPowerOfTwo(int n)
	{
		int i = 0;
		while (pow(2, i) < n)
		{
			i++;
		}
		if (pow(2, i) == n)
			return true;
		else
			return false;
	}
};
```