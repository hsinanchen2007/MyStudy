### 解题思路
对于`(()())(())(()(()))`，可以把它分为`(()())`，`(())`，`(()(()))`，可以看出每组的第一个`(`和最后一个`)`都不能加入到结果字符串，除此之外，其他全部加入到结果字符串即可。
**具体做法：**
1. 遇到左括号`(`，判断它是否为每组首个字符串(通过栈是否为空判断)。若不是，将其加入到结果字符串，将当前左括号`(`入栈
2. 遇到右括号`)`，判断它是否为每组最后一个`)`。若不是，将其加入到结果字符串，将栈顶元素出栈

### 代码

```cpp
class Solution {
public:
    stack<char> sk;
    string removeOuterParentheses(string S) {
        string ans = "";
        int i = 0;
        while(i<S.size()){
            char c = S[i];
            if(c == '('){
                if(!sk.empty()) ans += c;
                sk.push(c);
            }
            else{
                if(sk.size() != 1) ans += c;
                sk.pop();
            }
            i++;
        }
        return ans;
    }
};
```