![image.png](https://pic.leetcode-cn.com/c1ec174f0cd6dd283da7e1e4be42bb09b614e746980f860ea61434ec70cd9cf6-image.png)


### 解题思路
1. 遍历字符串（**注意特判，字符串为空，则直接返回true**）
2. 遇到左括号，进行入栈
3. 遇到右括号，
   ①首先判断栈是否为空，为空返回false
   ②出栈，进行匹配
   匹配不成功，返回false
   匹配成功，则什么都不做，进行下一次循环       
4. 若走到循环结束，说明字符串中所有括号能匹配，返回true

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(!s.length()) {
            return true;
        }
        int len = s.length();
        //数组stack 与 栈顶指针top模拟栈
        vector<char> stack(len,'0');
        int top = -1;
        
        for(int i = 0; i < len || top != -1; ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack[++top] = s[i];
            }
            else {
                if(top == -1) {
                    return false;
                }
                char match = stack[top--];
                if(!isMatch(match, s[i])) {
                    return false;
                }
            }
        }
        return true;
    }
    // 注意传参时的顺序，左括号为第一个参数，右括号为第二个参数
    bool isMatch(char left, char right) {
        switch(left) {
            case '(': return right == ')';
            case '{': return right == '}';
            case '[': return right == ']';
            default: return false;
        }
    }
};
```