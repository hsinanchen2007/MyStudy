### 解题思路
双栈，左括号放入层数最少的栈中，右括号匹配层数最多的栈

### 代码

```cpp
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<char> stack0, stack1;
		vector<int> result;
		int index = 0;

		for (string::iterator it = seq.begin(); it != seq.end(); it++)
		{
			if (*it == '(')
			{
				index = stack0.size() <= stack1.size() ? 0 : 1;
				index == 0 ? stack0.push_back(*it) : stack1.push_back(*it);
			}
			else 
			{
				index = stack0.size() >= stack1.size() ? 0 : 1;
				index == 0 ? stack0.pop_back() : stack1.pop_back();
			}
			result.push_back(index);
		}

		return result;
	}
};
```