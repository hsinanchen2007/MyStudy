```
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int len = s.size();

        string tmp;
        for(int i = 0; i <= len; i++){
            if(s[i] == ' '|| s[i] == 0){
                if(tmp.size() > 0){
                    if(ret.size() > 0) 
                        ret = tmp+" "+ret;
                    else
                        ret = tmp; 
                    tmp.clear();
                }
            } 
            else tmp += s[i];


        }
        return ret;
        
    }
};
```
