```python []
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s is None:
            return False
        start, end = 0, len(s)-1
        while start < end:
            while start < end and not s[start].isalpha() and not s[start].isdigit():
                start += 1
            while start < end and not s[end].isalpha() and not s[end].isdigit():
                end -= 1
            if start < end and s[start].lower() != s[end].lower():
                return False
            start += 1
            end -= 1
        return True
```
```java []
class Solution {
    public boolean isPalindrome(String s) {
        if(s == null){
            return false;
        }
        if(s.length() == 0){
            return true;
        }
        
        int front = 0;
        int end = s.length() - 1;
        
        while (front < end){
            while (front < s.length() && !isvalid(s.charAt(front))){
                front++;
            }
            if (front == s.length()){
                return true;
            }
            
            while(end >= 0 && !isvalid(s.charAt(end))){
                end--;
            }

            if (end == 0){
                return true;
            }
            
            if (Character.toLowerCase(s.charAt(front)) != Character.toLowerCase(s.charAt(end))){
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
    
    private boolean isvalid(char c){
        return Character.isLetter(c) || Character.isDigit(c);
    }
}
```

