```
class Solution {
public:
    int lengthOfLastWord(std::string s) 
    {
        int res = 0;
        s.erase(s.find_last_not_of(" /t/n/r") + 1);//去除后面的空格
        for(int i = 0;i<s.size();i++)
        {
            if (s[s.size()-i-1]==' ')
            {
                res = i;
                break;
            }
            if (s.size()-i-1 == 0)
                res = i+1;    
        }
        return res;
    }
};
```
