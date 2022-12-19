```
代码块class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int tag = 0;
        //如果s为空，也是对的
        if(s.empty())
            return true;
        //一个个扫描
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] == s[tag])
            {
                tag++;
                if(tag >= s.size())
                    return true;
            }
        }
        return false;
    }
};
```
