### 解题思路
   本题的解题关键点是如何反转每层括号中的字符串，从题目描述不难想到使用栈来解题，即建立一个栈，然后遍历给定的字符串，遇到左括号和字母就入栈，遇到右括号就出栈，直到当前栈顶元素是左括号，再把左括号pop出来。但是与以往的栈题目不同的是，本题需要将括号中的字符串反转，前面直接出栈获取的子串无法与上一层的字符串联系起来实现整体反转，因此我们在出栈之后需要再把pop出来的子串再压入栈，利用栈的后入先出的特性实现反转，并与上一层的字符串联系起来，最终可以实现整体多层括号的反转。具体实现见下面代码即可。
   需要注意的是，循环遍历之后反转的字符串还在栈中，我们需要再进行一次出栈，直到栈为空， 这样获得的字符串还需要再做一次反转，就可以获得最后的结果。

### 代码

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<char> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                temp.push(s[i]);
            } else {
                //需要将当前层次的字符串pop出来，做反转，然后再push进去
                string tmp;
                while (!temp.empty() && temp.top() != '(') {
                    tmp += temp.top();
                    temp.pop();
                }
                temp.pop(); //pop出左括号
                for (auto& elem: tmp) { //利用栈进行反转，将反转后的字符串压栈
                    temp.push(elem);
                }
            }
        }
        //最后将栈中的所有字符pop出来，再拼接到一起，最后反转即为最终结果
        while (!temp.empty()) {
            res += temp.top();
            temp.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```