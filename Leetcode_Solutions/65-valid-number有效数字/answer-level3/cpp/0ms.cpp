```
class Solution {
public:
    bool isNumber(string s) {
        bool a = false,b = false,c = false,d = true;
        int i = 0, j = s.size()-1; 
        while(s[i] == ' '){
            ++i;
        }
        while(s[j] == ' '){
            --j;
            if(s[j] == 'e'){
                return false;
            }
        }
        for(; i <= j; ++i){
            if(s[i] == ' '){
                if(a || b || c || !d){
                    return false;
                }
                continue;
            }
            if(s[i] == '+' || s[i] == '-'){
                if(a || (!d && !c)){
                    return false;
                }
                if(i > 0 && s[i-1] == '.'){
                    return false;
                }
                a = true;
            }
            else if(s[i] == '.'){
                if(b || c){
                    return false;
                }
                b = true;
                a = false;
            }
            else if(s[i] == 'e'){
                if(c || d){
                    return false;
                }
                c = true;
                a = false;
            }
            else if(s[i] < '0' || s[i] > '9'){
                return false;
            }
            else{
                d = false;
            }
        }
        return s[j] == 'e' || s[j] == '+' || s[j] == '-'|| d ? false:true;
    }
};
```
