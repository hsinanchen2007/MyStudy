逐步判断
```
class Solution {
public:
    bool isNumber(string s) {
        int len=s.size();
        if(len == 0) return false;
        int i=0;
        bool e=0, dot=0, num=0, end=0;
        while(s[i] == ' ') i++;
        if(s[i] == '+'||s[i] == '-') i++;
        while(i<len){
            if(s[i] >= '0' && s[i] <= '9' && !end){
                i++;num = 1;
            }
            else if(s[i] == 'e' && !end){
                if(num && !e){
                    e=1; num=0; dot=1; i++;
                    if(s[i] == '+'||s[i] == '-')
                        i++;
                }
                else return false;
            }
            else if(s[i] == '.' && !end){
                if(!dot && !e){
                    dot=1; i++;
                }
                else return false;
            }
            else if(s[i] == ' '){
                end=1; i++;
            }
            else return false;
        }
        return num;
    }
};
```
