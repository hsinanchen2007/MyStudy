### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //START TIME 2020.3.24 22:12
    //FINISH TIME 2020.3.24 22:50  性能和空间使用最佳
    //思路：逐个字符扫描，左括号入栈、右括号判断栈顶与右括号匹配弹栈，不匹配返回false 
    //遍历结束如果栈非空则不合法，栈为空则合法
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        const int MAX_LEN = 128;
        char char_map[MAX_LEN] = {'0'};
        char_map[')'] = '(';
        char_map[']'] = '[';
        char_map['}'] = '{';

        stack<char> s_char;
        char curr_char = ' ';

        for (int i = 0; i < s.length(); ++i) {
            curr_char = s[i];

            if (curr_char == '(' || curr_char == '[' || curr_char == '{') {
                s_char.push(curr_char);
            }
            if (curr_char == ')' || curr_char == ']' || curr_char == '}') {
                if (!s_char.empty() && s_char.top() == char_map[curr_char]) {
                        s_char.pop();
                }
                else {
                    return false;
                }
            }
        }
        //cout<<s_char.size()<<endl;
        if (s_char.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
```