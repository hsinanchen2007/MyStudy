### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        stack<char> stackOne;
        bool flag = false; //表示没有碰到#
        int len=0,choice;
        for(int i = s.size()-1;i>=0;i--)
        {
            if(flag){
                len = (s[i]-'0')+(s[i-1]-'0')*10;
                i--;
                choice = len - 10;
                if(choice>=0)
                {
                     stackOne.push(('j'+choice));
                     flag = false;
                }
                continue;
            }else if(s[i] == '#')
            {
                flag = true;
                len = 0;
                continue;
            }else 
            {
               stackOne.push(('a'+s[i]-'1'));
            }
        }
        string res = "";
        while (!stackOne.empty())
        {
            res+=stackOne.top();
            stackOne.pop();
        }
        return res;


    }
};
```