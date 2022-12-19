### 解题思路
做这类括号的题，一般都能想到用栈，遇到左括号入栈，遇到右括号出栈。
栈顶元素表示的最长有效括号开始地方的前一个位置，因此栈初始化的值为-1，
因为一开始处理时最长有效括号是索引0的前一个位置是-1
1. 如果s[i]=='(',索引i入栈
2. 如果s[i]==')',出栈
    - 如果栈不为空，此时栈顶的值就是此刻最长有效括号开始地方的前一个位置，i-stack.top()就是此时最长有效括号的长度。
    - 如果栈为空，说明没有左括号可匹配，更新最长有效括号起始位置，将索引i入栈

语言组织的不好，理解不了望见谅
### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0||s.size()==1)
            return 0;
        stack<int>left;
        left.push(-1);
        int max=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left.push(i);
            }
            else
            {
                left.pop();
                if(left.empty())
                {
                    left.push(i);
                }
                else
                {
                    int temp=i-left.top();
                    max=max>temp?max:temp;
                }
            }
        }
        return max;
    }
};
```