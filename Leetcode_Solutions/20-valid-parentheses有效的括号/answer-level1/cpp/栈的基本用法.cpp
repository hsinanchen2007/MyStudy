执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.4 MB
, 在所有 C++ 提交中击败了
83.56%
的用户

```C++ []
class Solution {
public:
    bool isValid(string s) {
        map<char, char> map;
        map[')'] = '(';
        map[']'] = '[';
        map['}'] = '{';
        stack<char> st;
        for(char c : s){
            if(map.count(c)){
                if(!st.empty() && map[c] == st.top())
                    st.pop();
                else 
                    return false;
            }
            else
                st.push(c);
        }
        if(st.empty())
            return true;
        return false;
    }
};

```
这题在学习栈的时候基本都是老生常谈的内容，不过这个题更为简洁，没有字母数字什么的只需要处理括号就可以了。
遇到右括号先判断是否为空栈，为空说明肯定无法匹配，在判断栈头的内容时候匹配。其他的都是左括号直接入栈就行了，所有的字符判断完后再在最后判断是否为空栈，因为可能出现全是左括号的情况。