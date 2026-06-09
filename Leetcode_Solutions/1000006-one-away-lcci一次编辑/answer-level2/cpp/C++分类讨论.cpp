class Solution {
public:
    bool oneEditAway(string first, string second) {
        string short_str;
        string long_str;
        if(first.length()<second.length())
        {
            short_str=first;
            long_str=second;
        }else{
            short_str=second;
            long_str=first;
        }
        int count=0;
        if(long_str.length()-short_str.length()>1)
            return false;
        else if(first.length()==second.length())
        {
            for(int i=0;i<short_str.length();i++)
            {
                if(first[i]!=second[i])
                    count++;
                if(count>1)
                    return false;
            }
            return true;
        }else{
            count=0;
            for(int i=0;i<short_str.length();i++)
            {
                if(count==0)
                {
                    if(short_str[i]!=long_str[i])
                        count=1;                    
                }
                if(count==1)
                {
                    if(short_str[i]!=long_str[i+1])
                        return false;
                }
            }
            return true;
        }
    }
};