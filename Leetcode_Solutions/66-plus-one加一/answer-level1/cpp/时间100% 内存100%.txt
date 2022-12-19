### 解题思路
最好不要修改输入数组

### 代码

```cpp
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto result(digits);
		for (int i = result.size() - 1; i >= 0; i--)
		{
			result[i]++;
			result[i] %= 10;
			if (result[i] != 0)
				return result;
		}
		result.insert(result.begin(), 1);
		return result;
	}
};
```