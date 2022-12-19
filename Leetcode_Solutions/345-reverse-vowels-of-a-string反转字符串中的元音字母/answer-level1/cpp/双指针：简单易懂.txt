```
class Solution {
public:
    bool isVowel(char c){
        if(c >= 'a'){
            c = c - ('a' -'A');
        }
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int fst = 0;
        int lst = s.size() - 1;
        while(fst < lst){
            if(isVowel(s[fst]) && isVowel(s[lst])){
                char tmp = s[fst];
                s[fst] = s[lst];
                s[lst] = tmp;
                fst ++;
                lst--;
                continue;
            }
            if(!isVowel(s[fst])){
                fst++;
            }
            if(!isVowel(s[lst])){
                lst--;
            }
        }
        return s;
    }
};
```
