思路如下：
1. 遇到左括号的时候，直接压入栈中
2. 遇到右括号的时候：a. 如果栈为空，直接返回false b.如果栈顶括号不是匹配的左括号，直接返回false
3. 遍历完成后，如果栈为空则返回true

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> optr;
        for (auto c : s)
        {
            switch (c){
            case '(':
            case '{':
            case '[': optr.push(c); break;
            case ')':
                if (optr.empty()) return false;
                if (optr.top() != '(') return false;
                optr.pop();
                break;
            case '}':
                if (optr.empty()) return false;
                if (optr.top() != '{') return false;
                optr.pop();
                break;
            case ']':
                if (optr.empty()) return false;
                if (optr.top() != '[') return false;
                optr.pop();
                break;
            }
        }
        return optr.empty() ? true : false;
    }
};
```
时间复杂度：只需要一次遍历，所以是O(n)
空间复杂度：最坏情况是都是左括号，全部入栈，所以是O(n)
    