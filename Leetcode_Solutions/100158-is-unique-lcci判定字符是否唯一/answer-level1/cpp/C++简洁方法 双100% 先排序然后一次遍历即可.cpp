```
class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(),astr.end());
        for(int i=1;i<astr.length();++i){
            if(astr[i]==astr[i-1]) return false;
        }
        return true;
    }
};
```
