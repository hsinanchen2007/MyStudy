```
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string ans;
        while(ss){
           ss >> ans;
        }
        return ans.size();
    }
};
```
