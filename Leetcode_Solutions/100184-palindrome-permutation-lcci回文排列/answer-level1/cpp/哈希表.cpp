```
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> hmap;
        int lg=s.length();
        for(int i=0;i<lg;++i) {
            if(hmap.find(s[i])!=hmap.end()) {
                hmap.erase(s[i]);
            }
            else {
                hmap.insert(unordered_map<char,int>::value_type (s[i],i));
            }
        }
        if(hmap.empty()||hmap.size()==1) return true;
        else return false;
    }
};
```
