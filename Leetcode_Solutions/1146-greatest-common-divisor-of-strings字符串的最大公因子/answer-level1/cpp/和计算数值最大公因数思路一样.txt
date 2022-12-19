```
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while(!str1.empty()){
            if(str1==str2) return str1;
            else if(str1.size()>str2.size() && str1.find(str2)==0){
                str1=str1.substr(str2.size());
            }
            else if(str1.size()<str2.size() && str2.find(str1)==0){
                str2=str2.substr(str1.size());
            }
            else return "";
        }
        return "";
    }
};
```
