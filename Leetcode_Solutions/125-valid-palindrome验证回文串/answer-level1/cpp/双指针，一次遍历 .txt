两个指针分别从左右向中间移动，不是字母或数字的直接跳过，如果字母或数字不相等，直接返回 false;

```
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0) return true;
        
        for(int i=0, j=s.size()-1; i<j; ){
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            
            if(i >= j) return true;
            
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;
        }
        
        return true;
    }
};
```
