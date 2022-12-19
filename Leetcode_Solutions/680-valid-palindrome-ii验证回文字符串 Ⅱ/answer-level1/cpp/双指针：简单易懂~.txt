```
class Solution {
public:
    bool validPalind(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end){
            if(s[start] ==  s[end]){
                start++;
                end--;
            }else{
                return false;   
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end){
            if(s[start] ==  s[end]){
                start++;
                end--;
            }else{
                if(validPalind(s.substr(start + 1, end - start)) == true
                    || validPalind(s.substr(start, end - start)) == true){
                    return true;
                }else{
                    return false;
                }   
            }
        }
        return true;
    }
};
```
