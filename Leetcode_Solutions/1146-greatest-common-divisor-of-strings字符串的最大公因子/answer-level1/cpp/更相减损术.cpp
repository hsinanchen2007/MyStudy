int error = 0;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size())
        {
            string tt;
            tt.assign(str1);
            str1.assign(str2);
            str2.assign(tt);
        }
        do
        {
            string tem = minus(str1, str2);
            if (tem.size() == 0)
                break;
            if (error == 1)
            {
                error = 0;
                return "";
            }
            if (tem.size() >= str2.size())
            {
                str1.assign(tem);
            }
            else
            {
                str1.assign(str2);
                str2.assign(tem);
            }
        } while (true);
        return str2;
    }
    string minus(string s1, string s2)
    {
        if (s1.find(s2))
        {
            error = 1;
            return "error";
        }
        string res = s1.substr(s2.size());       
        return res;
    }
};