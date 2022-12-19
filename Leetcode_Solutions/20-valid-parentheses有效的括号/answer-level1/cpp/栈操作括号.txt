![image.png](https://pic.leetcode-cn.com/09f6cc83b0a0825555f6a8155c23546c632933e9b90b6aca8db1bd7a83db38b8-image.png)

### 解题思路
利用栈的先进后出的特性，挨个将左括号入栈，遇到右括号判断栈顶是否匹配，匹配则出栈，否则返回false。遍历完字符串若栈内还有元素则返回false。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.size() ==0) return true;
        char tmp;
        stack<char> mystack1;
        for(int i=0;i<s.size();i++){
            
            switch(s[i]){
                case '(':
                    mystack1.push('(');
                    continue;
                case '[':
                    mystack1.push('[');
                    continue;
                case '{':
                    mystack1.push('{');
                    continue;
                case ')':
                    if(mystack1.size() == 0) return false;
                    tmp = mystack1.top();
                    if(tmp == '('){
                        mystack1.pop();
                    }else{
                        return false;
                    }
                    continue;
                case ']':
                    if(mystack1.size() == 0) return false;
                    tmp = mystack1.top();
                    if(tmp == '['){
                        mystack1.pop();
                    }else{
                        return false;
                    }
                    continue;
                case '}':
                    if(mystack1.size() == 0) return false;
                    tmp = mystack1.top();
                    if(tmp == '{'){
                        mystack1.pop();
                    }else{
                        return false;
                    }
                    continue;
            }
        }
        if(mystack1.size() != 0) return false;
        return true;
    }
};
```