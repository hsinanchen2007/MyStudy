```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ssize=s.size(),tsize=t.size();
        int sp=0,tp=0;
        while(sp<ssize&&tp<tsize){
            while(tp<tsize&&s[sp]!=t[tp]){
                ++tp;
            }
            if(tp<tsize){
                ++sp;
            }
            ++tp;
        }
        if(sp==ssize){
            return true;
        }
        return false;

    }
};
```
