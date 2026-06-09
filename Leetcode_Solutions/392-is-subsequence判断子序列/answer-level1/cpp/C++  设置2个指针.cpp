// ```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,j;
        i=j=0;
        for (; i<t.size(); i++) 
            if (t[i]==s[j]) j++;
        
        if (j==s.size())  return true;
        else return false;
    }
};

// ```

// **后续的问题好像没什么思路😂**