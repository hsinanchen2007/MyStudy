### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        
        int size = s.size();
        stack<string> temstack;
        string temstring;
        for(int i = 0;i < size;i++)
        {
            if(s[i] != ' ')
            {
                temstring += s[i];
            }
            else
            {
                if(temstring.size() != 0)
                {
                    temstack.push(temstring);
                }
                temstring.clear();
            }
        }

        if(temstring.size())
        {
            temstack.push(temstring);
        }

        string ans;
        int temsize = temstack.size();
        for(int i = 0; i < temsize;i++)
        {
            if(i != temsize - 1)
            {
                ans += temstack.top() + ' ';
                temstack.pop();
            }
            else
            {
                ans += temstack.top();
            }
        }
        return ans;

    }
};
```