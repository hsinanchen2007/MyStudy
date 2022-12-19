执行用时 :60 ms, 在所有 C++ 提交中击败了52.15%的用户
内存消耗 :15.2 MB, 在所有 C++ 提交中击败了48.78%的用户

看了官方题解，才知道o(1)的算法并不是原地算法，因此此解法并非原地解法
### 代码

```cpp
class Solution {
public:
	void reverseString(vector<char>& s) 
	{
		int i = 0, j = s.size() - 1;
		char t;
		while (i <= j )
		{
			t = s[j];
			s[j] = s[i];
			s[i] = t;
			++i;
			--j;
		}
	}
};
```