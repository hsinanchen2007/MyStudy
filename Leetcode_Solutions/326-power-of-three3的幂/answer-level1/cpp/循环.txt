执行用时 :8 ms, 在所有 C++ 提交中击败了98.81%的用户
内存消耗 :7.4 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	bool isPowerOfThree(int n) 
	{
		if ( n == 0 )
			return false;
		while (n % 3 == 0)
		{
			n /= 3;
		}
		if (n == 1)
			return true;
		else
			return false;
	}
};
```