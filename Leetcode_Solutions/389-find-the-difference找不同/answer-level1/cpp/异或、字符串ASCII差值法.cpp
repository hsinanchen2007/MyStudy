```
class Solution1 {
public:
    char findTheDifference(string s, string t) {
         char ret = 0;
         for (int i = 0; i < s.length(); ++i) {
             ret ^= s[i];
         }
         for (int i = 0; i < t.length(); ++i) {
             ret ^= t[i];
         }
         return ret;
    }
};

class Solution2 {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            ret += t[i] - s[i];
        }   
        return ret + t[t.length()-1];
    }
};
```
