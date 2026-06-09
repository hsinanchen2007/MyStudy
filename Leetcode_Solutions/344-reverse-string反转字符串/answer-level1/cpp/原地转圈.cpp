``` c++
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1) return;
        for(int i = 0; i <(s.size())/2;i++){
            int tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size()-1-i] = tmp;
        }
    }
};
```
