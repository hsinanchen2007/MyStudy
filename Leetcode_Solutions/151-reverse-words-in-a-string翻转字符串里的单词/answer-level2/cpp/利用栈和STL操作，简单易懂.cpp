### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int pos1 = s.find_first_not_of(' '); //首先找到第一个不为空格的pos
        int pos2 = s.find_first_of(' ',pos1); //从pos1开始找第一个为空格的位置
        while (pos1 != string::npos && pos2 != string::npos) { //两个位置都找到了，继续操作
            st.push(s.substr(pos1, pos2 - pos1)); //压入子串到栈中
            pos1 = s.find_first_not_of(' ', pos2); 
            pos2 = s.find_first_of(' ', pos1);
        }
        if (pos1 != string::npos) st.push(s.substr(pos1)); //最后处理特殊情况，例如“the sky is blue”结尾没有空格，所以pos2==string::npos，此时pos1停在b这个地方，需要单独处理
        string res;
        while (!st.empty()) {
            string temp = st.top();
            st.pop();
            res += temp;
            if (!st.empty()) res += ' '; //如果还有后续单词，添加空格
        }
        return res;
    }
};
```