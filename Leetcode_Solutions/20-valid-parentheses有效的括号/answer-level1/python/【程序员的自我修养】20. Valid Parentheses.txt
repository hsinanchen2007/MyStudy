### 解题思路


利用一个栈，不断地往里压左括号，一旦遇上了一个右括号，我们就把栈顶的左括号弹出来，
表示这是一个合法的组合，以此类推，直到最后判断栈里还有没有左括号剩余。


```python []
ValidMap = {
    '(': ')',
    '[': ']',
    '{': '}',
}


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s is None:
            return True
        # 1. 使用额外的栈处理
        stack = []
        # 如果遇到开括号，我们只需将其推到栈上即可。这意味着我们将稍后处理它，
        # 如果我们遇到一个闭括号，那么我们检查栈顶的元素。
        # 如果栈顶的元素是一个 相同类型的 左括号，那么我们将它从栈中弹出并继续处理。
        # 否则，这意味着表达式无效。
        for char in s:
            if char in ValidMap:
                # 左括号
                stack.append(char)
            else:
                # 右括号
                if len(stack) > 0:
                    s = stack.pop()
                    if ValidMap[s] != char:
                        return False
                else:
                    return False
        return len(stack) <= 0
```

```c++ []
class _20_Valid_Parentheses
{
private:
	map<char, char> ValidMap = {
	{'(', ')'},
	{'[' , ']'},
	{'{' , '}'},
	};

public:
	bool isValid(string s) {
		//1. 先建立一个映射表，key是左括号，value是右括号 4 ms 76%
		//然后遇到左括号入栈，遇到右括号出栈，最后栈如果是空的就是valid的

		stack<int> stack;
		for (char oneChar : s)
		{
			map<char, char>::iterator it = ValidMap.find(oneChar);
			if (it==ValidMap.end())
			{
				if (stack.empty())
					return false;

				if (ValidMap[stack.top()] != oneChar)
					return false;

				stack.pop();
			}
			else
			{
				stack.push(oneChar);
			}
		}

		return stack.empty();
	}
};
```


![20.gif](https://pic.leetcode-cn.com/e5fe11d245f9d820e6ff40d8c862633077178d754ec4891b1bdf31568799e119-20.gif)
