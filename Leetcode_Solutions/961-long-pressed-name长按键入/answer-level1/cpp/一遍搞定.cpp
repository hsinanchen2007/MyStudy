```
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j=0;
        for(int i=0;i<name.length();i++)
        {
            if(i+1 < name.length())
            {
                if(name[i] == name[i+1])
                {
                    if(name[i] != typed[j])
                        return false;
                    else
                    {
                        j++;
                        if(i < name.length() && j == typed.length())
                            return false;
                    }
                }
                else
                {
                    if(name[i] != typed[j])
                        return false;
                    while(name[i] == typed[j])
                    {
                        j++;
                        if(i < name.length() && j == typed.length())
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
```