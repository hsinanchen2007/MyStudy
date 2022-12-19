### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> sta;
        string temp;
        for (int i = 0; i < s.size(); i++) {
            // 非空格，临时字符串获取单词
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } 
            // 遇到空格临时字符串入栈
            else {
                if (temp.size() != 0) {
                    sta.push(temp);
                }
                temp.clear();
            }
        }
        // 处理原字符串的最后一个单词，可能由于没有以空格结尾导致temp获取之后并没有入栈
        if (temp.size() != 0) {
            sta.push(temp);
        }
        string res;
        while (sta.size() > 0) {
            // 栈里有不止一个单词，以空格拼接单词，出栈
            if (sta.size() != 1) {
                res += sta.top();
                res += " ";
                sta.pop();
            } 
            // 栈里剩下最后一个单词，不需要拼接空格，出栈
            else if (sta.size() == 1) {
                res += sta.top();
                sta.pop();
            }
        }
        return res;
    }
};


#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseWords(string s) {
    stack<string> sta;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            temp.push_back(s[i]);
        } 
        else {
            if (temp.size() != 0) {
                sta.push(temp);
            }
            temp.clear();
        }
    }
    if (temp.size() != 0) {
        sta.push(temp);
    }
    string strout;
    while (sta.size() > 0) {
        if (sta.size() != 1) {
            strout += sta.top();
            strout += " ";
            sta.pop();
        } 
        else if (sta.size() == 1) {
            strout += sta.top();
            sta.pop();
        }
    }
    return strout;
}

int main() {
    cout << reverseWords("the sky is blue") << endl;
}


```