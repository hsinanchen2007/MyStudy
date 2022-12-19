```
class Solution {
public:
    vector<string> p;
    vector<string> letterCasePermutation(string S) {
       
        fullsort(S, 0);
        return p; 
    }
    
    void fullsort(string s, int k)
    {
        if(k == s.size())
        {
            p.push_back(s);
            return;
        }
        
        fullsort(s, k + 1);
        if(isalpha(s[k]))
        {
            s[k] = s[k] ^ (1 << 5); //转变大小写
            fullsort(s, k + 1);
        }
    }
};
```
