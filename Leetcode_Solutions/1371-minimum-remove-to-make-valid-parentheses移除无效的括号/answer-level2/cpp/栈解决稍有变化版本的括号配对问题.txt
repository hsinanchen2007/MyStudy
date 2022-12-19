### 栈模拟
&emsp;&emsp;比赛的时候把题目想复杂了，感觉这道题目不应该只是简单的堆栈模拟去除括号，迟迟没敢下手。昨晚睡觉前想了挺久的，没有想到考虑范围外的情况，于是还是用栈模拟试着提交了，结果通过了。事实证明，有时候问题不要想太复杂，要敢于尝试。

&emsp;&emsp;常规的判断括号字符串是不是合法的括号对，我们应该已经很熟悉了。
`遇到左括号，则压入堆栈；遇到右括号，则判断堆栈是否空；此时，如果堆栈为空，则字符串非法；反之，则弹出栈顶的左括号；最终遍历完字符串之后，如果堆栈非空，则字符串非法。`
上面的算法有个特点，压入堆栈的一定都是左括号，右括号不会被压入堆栈。

&emsp;&emsp;然而这一题却不同，我们需要将非法的右括号同样也压入堆栈，在遍历完字符串之后，将堆栈内的括号全部从字符串中移除，得到的即为这道题的答案。最后查看堆栈的话，同样也可以发现一个特点，堆栈内的右括号一定是在左括号之前。（废话！如果左括号在前，不就左右配对消失了么。）

```
class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<unsigned> parenthesesIndexStack;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				parenthesesIndexStack.push(i);
			} else if (s[i] == ')') {
				if (!parenthesesIndexStack.empty() && s[parenthesesIndexStack.top()] == '(')
					parenthesesIndexStack.pop();
				else
					parenthesesIndexStack.push(i);
			}
		}

		while (!parenthesesIndexStack.empty()) {
			s.erase(parenthesesIndexStack.top(), 1);
			parenthesesIndexStack.pop();
		}

		return s;
	}
};
```
我果真不适合写题解，写文章啊！