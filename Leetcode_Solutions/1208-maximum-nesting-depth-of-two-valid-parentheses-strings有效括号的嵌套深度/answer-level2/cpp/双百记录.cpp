### 解题思路
平均分配栈内(来保证均匀，使得最终max(A,B)最小

### 代码

```cpp
class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> depth_v;
		stack<char> brackets;
		int pos = 0;
		while (pos < seq.size())
		{
			//入栈
			if (seq[pos] == '(')
			{
				brackets.push(seq[pos]);
				//栈内奇数分给A偶数分给B
				depth_v.push_back(brackets.size() % 2);
			}
			else
			{
				depth_v.push_back(brackets.size() % 2);
				brackets.pop();
			}

			pos++;
		}
		return depth_v;
	}
};


```