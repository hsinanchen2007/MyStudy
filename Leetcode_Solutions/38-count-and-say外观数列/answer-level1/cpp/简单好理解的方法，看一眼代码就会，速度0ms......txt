### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string cs = "1";
        for(int i=0;i<n-1;i++)
        {
            nextString(cs);
        }
        return cs;
    }
    void nextString(string &s)
    {
        string outs;
        int num=1;
        for(int i=0;i<s.size();++i)
        {
            if(i==s.size()-1)
            {
                outs.push_back('0'+num);
                outs.push_back(s[i]);
            }
            else if(s[i]!=s[i+1])
            {
                outs.push_back('0'+num);
                outs.push_back(s[i]);
                num = 1;
            }
            else num++;
        }
        s = outs;
    }
};
```