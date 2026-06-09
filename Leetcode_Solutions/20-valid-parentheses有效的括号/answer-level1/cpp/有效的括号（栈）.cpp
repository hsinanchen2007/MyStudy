### 解题思路
1、判断s.size()是否为奇数，是则返回false；
2、遍历s的每个char，为左括号则入栈，为右括号则判断是否与栈顶括号元素相匹配，是则pop否则false
3、以此保证每次遇到匹配括号就出栈
4、最后判断栈是否为空，是则返回true
### 代码

```cpp
class Solution {
private:
stack<int> validB;
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        for(char c : s){
            if(c == '(' || c == '{' || c == '[') validB.push(c);
            else if(!validB.empty()){
                if(c == ')' && validB.top() != '(') return false;
                if(c == ']' && validB.top() != '[') return false;
                if(c == '}' && validB.top() != '{') return false;
                validB.pop();
            }
            else return false;
        }
        if(validB.empty()){
            return true;
        }
        else return false;
    }
};
```