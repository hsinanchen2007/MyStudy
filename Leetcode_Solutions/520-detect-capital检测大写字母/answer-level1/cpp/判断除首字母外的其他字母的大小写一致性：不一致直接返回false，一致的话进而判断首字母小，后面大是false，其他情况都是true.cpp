```
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        string head = "upper", other = "upper";
        if(word.length() == 1)
        {
            flag = true;
        }
        else
        {
            head = (word[0] >= 'A' && word[0] <= 'Z')?"upper":"lower";
            other = (word[1] >= 'A' && word[1] <= 'Z')?"upper":"lower";
            for(int i=2;i<word.length();i++)
            {
                if(other != ((word[i] >= 'A' && word[i] <= 'Z')?"upper":"lower"))
                    return false;
            }
            if(head == "lower" && other == "upper")
                flag = false;
            else
                flag = true;
        }
        return flag;
    }
};
```