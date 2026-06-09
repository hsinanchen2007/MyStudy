```
class Solution {
public:
    bool isUnique(string astr) 
    {
        int check = 0;
        for(char c:astr)
        {
            if(check&(1<<(c-'a')))
            {
                return false;
            }
            else
            {
                check |= (1<<(c-'a'));
            }
        }

        return true;
    }
};
```