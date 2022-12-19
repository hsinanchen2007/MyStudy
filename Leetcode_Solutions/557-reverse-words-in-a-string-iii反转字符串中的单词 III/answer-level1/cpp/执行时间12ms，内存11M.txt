# 用string::find和std::reverse
```
class Solution {
public:
    string reverseWords(string s) {
        auto start = 0;
        while(1){
            auto pos = s.find(" ",start);
            if(pos != string::npos){
                std::reverse(s.begin()+start,s.begin() + pos);
                start = pos+1;
            }else{
                std::reverse(s.begin()+start,s.end());
                break;
            }
        }
        return s;
    }
};
```
