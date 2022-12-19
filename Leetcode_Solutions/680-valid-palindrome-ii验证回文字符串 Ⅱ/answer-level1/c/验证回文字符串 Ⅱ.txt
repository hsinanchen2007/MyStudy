```
bool checkIsPalindrome(char* s,int left,int right) {
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        } else {
            left++;
            right--;
        }
    }
    return true;
}
bool validPalindrome(char * s){
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    
    while(left < right) {
        if(s[left] == s[right]) {
            left++;
            right--;
        } else {
            if(checkIsPalindrome(s,left+1,right)) {
                return true;
            }
            if(checkIsPalindrome(s,left,right-1)) {
                return true;
            }
            return false;
        }
    }
    return true;
}
```
