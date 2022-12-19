执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
	bool canWinNim(int n) 
	{
		if (n % 4 == 0) return false;
		else return true;
	}
};
```