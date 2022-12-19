//遍历字符串，仅左括号入栈，遇到右括号，则看是否与栈顶元素括号匹配，如果不匹配，则串是无效的 (注意：栈需要先判空，如果栈为空，则表示该串是无效的)
//最后还要判断栈是否为空， 比如 "(("的情况，因为无法触发括号匹配操作，出栈的次数少于入栈的次数

```cpp
class Solution {
public:
    bool isValid(string s) {

        if (s.empty()) //注意：空字符串可被认为是有效字符串
            return true;

        if (s.size() % 2 == 1) //奇数个
            return false;

        stack<char> stack;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
            {
                stack.push(s.at(i));
            }
            else
            {
                if (stack.empty())
                    return false;

                if ((s.at(i) == ')' && '(' != stack.top()) || (s.at(i) == ']' && '[' != stack.top()) || ((s.at(i) == '}' && '{' != stack.top())))
                    return false;

                stack.pop();
            }
        }

        return stack.empty();
    }
};