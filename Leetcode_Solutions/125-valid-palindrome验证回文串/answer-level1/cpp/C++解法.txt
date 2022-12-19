class Solution {
public:
    bool isPalindrome(string s)
    {
        if(s.size() == 0)
        {
            return true;
        }

        int i=0,j=s.size()-1;
        
        while(i<j)
        {
            /*标点符号跳过*/
            /*空格跳过*/
            if(ispunct(s[i])||isspace(s[i]))
            {
                i++;
                continue;
            }

            if(ispunct(s[j])||isspace(s[j]))
            {
                j--;
                continue;
            }           

            /*相同则继续，否则返回false*/
            if(tolower(s[i])==tolower(s[j]))
            {
                i++;
                j--;
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};