0ms,8.9MB

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        //暴力解
        if(s.empty())return 0;
        else{
            int end = 0;
            for(int i = s.size();i > 0;i--)
            {
                if((s[i] == ' ' || s[i] == '\0') && s[i-1] != ' ')
                    end = i;
                else if(s[i] != ' ' &&s[i] != '\0' && s[i-1] == ' ')
                {
                    return (end - i);
                }
            }
            //还有两种可能，全为空格或字首为字符
            //全为空格时，end为0，可直接返回
            //字首为字符时，可直接返回end
            return end;
        }
    }
};
```