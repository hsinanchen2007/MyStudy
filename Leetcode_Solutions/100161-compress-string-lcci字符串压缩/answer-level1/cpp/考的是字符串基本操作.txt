
没有特殊之处
```
class Solution {
public:
    string compressString(string S) {
        int n=0;
        string S_re;
        char last;
        for(char c:S){
            if(!n) {
                S_re.push_back(c);
                last=c;
                ++n;
            }
            else if(c==last){
                ++n;
            }
            else{
                S_re.append(to_string(n));
                n=1;
                last=c;
                S_re.push_back(c);
            }
        }
        S_re.append(to_string(n));
        if(S.length()<=S_re.length()) return S;
        else return S_re;
    }
};
```
