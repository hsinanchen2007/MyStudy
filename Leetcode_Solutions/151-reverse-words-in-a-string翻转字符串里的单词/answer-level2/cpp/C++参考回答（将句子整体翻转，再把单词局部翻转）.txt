```
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
               for(int j = i+1; j <= s.size(); j++){
                   if(s[j] == ' ' || j == s.size()){
                        reverse(s.begin()+i, s.begin()+j);
                        string temp(s.begin()+i, s.begin()+j);
                        if(!cnt)    res += temp;
                        else    res += (' '+temp);
                        cnt++;
                        i = j;
                        break;
                   }
                } 
            }
        }
        return res;
    }
};
```
