C++:异或法
class Solution {
public:
    char findTheDifference(string s, string t) {
      s=s+t;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            res^=s.at(i);
        }
        return (char)res;
    }
};
C++:求差值
class Solution {
public:
    char findTheDifference(string s, string t) {
      int i,res=0;
        for(i=0;i<s.size();i++)
        {
            res+=(int)t[i]-(int)s[i];
        }
        return char(res+(int)t[i]);
    }
};
