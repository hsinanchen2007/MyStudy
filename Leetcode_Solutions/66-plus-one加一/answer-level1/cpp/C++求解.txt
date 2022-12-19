### 解题思路
主要运用C++中的逆向迭代器
### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator it = digits.rbegin();
		while (it != digits.rend())
		{
			(*it)++;
			if (*it == 10)
			{
				*it = 0;
				it++;
			}
			else
			{
				break;
			}
		}
		if (it == digits.rend())
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
    }
};
```