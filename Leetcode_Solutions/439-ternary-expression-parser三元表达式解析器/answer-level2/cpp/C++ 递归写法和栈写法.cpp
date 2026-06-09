用栈真的有点烧脑 还是递归舒服啊......

```cpp
class Solution {
public:
    string parseTernary(string expression) {
	if (expression.length() == 1)
	    return expression;
	for (int i = expression.length() - 1; i >= 0; i -= 2)
	    if (expression[i - 3] == '?' && expression[i - 1] == ':')
		return parseTernary(expression.substr(0, i - 4) 
		+ (expression[i - 4] == 'T' ? expression[i - 2] : expression[i - 0]) 
		+ expression.substr(i + 1));
	return "";
    }
};
```
不过暂时没想到优化拷贝开销

下面是栈的 比较简单的写法

```cpp
class Solution {
public:
    string parseTernary(string expression) {
	stack<char> s1;
	for (int i = expression.length() - 1; i >= 2; i -= 2) {
	    if (expression[i - 1] == ':')
		s1.push(expression[i]);
	    else {
		expression[i - 2] = expression[i - 2] == 'T' ? expression[i] : s1.top();
		s1.pop();
	    }
	}
	return { expression[0] };
    }
};
```