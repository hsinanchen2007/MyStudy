### 解题思路
std::to_string()

### 代码

```cpp
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		string str = to_string(x);
		for (int i = 0; i < str.size(); i++)
			if (str[i] != str[str.size() - i - 1])
				return false;
		return true;

	}
};
```