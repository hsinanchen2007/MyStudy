### 解题思路
（第一次写题解 ） 采用单调栈当单调递增时入栈，最后我们会放过来求单调栈内的矩形面积。当违背单调栈的条件时（例如第二个2的出现）此时栈内时1，5，6.现在，需要算出6条单个和5，6一起哪个大。注意，每次入栈的后一个，来算前一个。

### 代码

```cpp
static auto speedup = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }(); 
    class Solution {
  public:
	  int largestRectangleArea(vector<int>& heights) {
		  stack<int>s;
		  int n = heights.size();
		  s.push(-1);
		  int curindex = 0;
		  int res = 0;
		  while (curindex < n)
		  {
			  while (s.top() != -1 && heights[s.top()] >= heights[curindex])
			  {
				  int tem = s.top();
				  s.pop();
				  res = max(res, heights[tem] * (curindex - s.top() - 1));
			  }
			  s.push(curindex++);
		  }
		  while (s.top() != -1)
		  {
			  int tem = s.top();
			  s.pop();
			  res = max(res, heights[tem] * (n - s.top() - 1));
		  }
		  return res;
	  }
  };
```