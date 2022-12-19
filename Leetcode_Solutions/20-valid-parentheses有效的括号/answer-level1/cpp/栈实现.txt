### 解题思路
- 采用栈的思想
    - 左括号入栈
    - 右括号检测
        - 栈空 判false
        - 不匹配 判false  

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        // 采用栈
        // 同时给定权限值
        // 2020 3 24 10:12
        map<char, int> priority =
        {

            {'{',0},
            {'[',1},
            {'(',2},
            {')',3},
            {']',4},
            {'}',5}
        };
        stack<char> mystack; //存储元素
        for(int i=0; i<s.size(); ++i){
            if(priority[s[i]] < 3){
                mystack.push(s[i]);
            }//左括号
            else{
                if(mystack.empty()) return false;
                else{
                    if(priority[s[i]] + priority[mystack.top()] != 5) return false; // 不匹配
                    else mystack.pop(); //出栈
                }
            }
        }
        return mystack.empty();
        // error: 可能不存在栈顶元素
    }
};
```