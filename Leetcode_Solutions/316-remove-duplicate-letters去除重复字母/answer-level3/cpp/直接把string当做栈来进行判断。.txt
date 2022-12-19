### 解题思路
此处撰写解题思路
题目不容易想出解法是利用单调栈进行解的。
当掉递增栈，如果当前元素小于栈顶元素且栈顶元素在后边字符串中还有重复的，则栈顶出栈。
### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string strSt;  // string 直接作为栈更方便

        for (int i = 0; i < s.size(); i++) {
            if (strSt.find(s[i]) != string::npos) {  // 字符已经出存在，则不需要加入了  
                continue;
            }
            //栈尾元素大于当前元素，且栈尾元素在后续字符串中还有，则栈顶出栈。
            while (!strSt.empty() && strSt.back() > s[i] && s.find(strSt.back(), i) != string::npos) {
                cout << strSt.back() << endl; 
                strSt.pop_back();
            }
            strSt.push_back(s[i]);
        }

        return strSt;
    }
};
```