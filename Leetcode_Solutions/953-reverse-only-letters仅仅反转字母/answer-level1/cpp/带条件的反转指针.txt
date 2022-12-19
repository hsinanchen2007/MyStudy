```
class Solution {
public:
    bool isAlpha(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    string reverseOnlyLetters(string S) {
        vector<char> tmp;
        for(auto c : S) tmp.push_back(c);
        int i=0, j=tmp.size()-1;
        while(i < j)
        {
            if(isAlpha(tmp[i]) == false)
            {
                i++;
                continue;
            }
            
            if(isAlpha(tmp[j]) == false)
            {
                j--;
                continue;
            }
            
            char t = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = t;
            i++;
            j--;
        }    
        string res = "";
        for(auto c : tmp) res += c;
        return res;
    }
};
```