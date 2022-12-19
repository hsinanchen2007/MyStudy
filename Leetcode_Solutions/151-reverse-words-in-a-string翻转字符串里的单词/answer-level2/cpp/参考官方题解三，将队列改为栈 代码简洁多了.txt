通过空格分隔字符串 保存一个临时变量 ，用栈保存字符串

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        if(s == " " || s == "") return "";
        int n = 0;
        string str = "";
        string ans = "";
        s = s + " ";
        for(auto i: s)
        {
            if(i == ' ')
            {
                stk.push(str);
                str = "";
            }
            else
            {
                str += i;
            }
        }
        while(!stk.empty())
        {
            if(stk.top() == "")
            {
                stk.pop();
            }
            else
            {
                ans += stk.top();
                stk.pop();
                ans += " ";
            }
        }
        
        if(ans.size() > 0)
        {
            ans.pop_back();
        }
        cout << ans;
        return ans;
    }
};
```
改为原地
```
class Solution {
public:
    string reverseWords(string s) {
        //stack<string> stk;
        //if(s == " " || s == "") return "";
        //int n = 0;
        string str = "";
        string ans = "";
        s = s + " ";
        for(auto i: s)
        {
            if(i == ' ')
            {
                //stk.push(str);
                if(str == "")
                {
                    continue;
                }
                else
                {
                    str = str + " ";
                    ans = str + ans;
                }
                str = "";
            }
            else
            {
                str += i;
            }
        }
        /*while(!stk.empty())
        {
            if(stk.top() == "")
            {
                stk.pop();
            }
            else
            {
                ans += stk.top();
                stk.pop();
                ans += " ";
            }
        }*/
        
        if(ans.size() > 0)
        {
            ans.pop_back();
        }
        cout << ans;
        return ans;
    }
};
```
