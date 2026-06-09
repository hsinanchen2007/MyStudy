```
#define ISNUM(x) ((x) >= '0' && (x) <= '9')
#define ISLETTERH(x) ((x) >= 'A' && (x) <= 'Z')
#define ISLETTERL(x) ((x) >= 'a' && (x) <= 'z')
#define TOLOWER(x) ((x) - ('a' - 'A'))

bool isPalindrome(char * s){
    
    if (s == NULL){
        return true;
    }
    
    int len = strlen(s);
    
    if (len == 0 || len == 1){
        return true;
    }
    
    int left = 0;
    int right = len - 1;
    
    for (; left <= right; left++) {
        if (!( ISNUM(s[left]) || ISLETTERH(s[left]) || ISLETTERL(s[left]))){
            continue;
        }
        
        while (right >= left) {
            if (ISNUM(s[right]) || ISLETTERH(s[right]) || ISLETTERL(s[right])){
                break;
            }
            
            right--;
        }
        
        if ( (ISNUM(s[left]) && !ISNUM(s[right])) || (ISNUM(s[right]) && !ISNUM(s[left]))) {
            return false;
        }
       
        if (!( s[left] == s[right] || TOLOWER(s[left]) == s[right] || s[left] == TOLOWER(s[right]))) {
            return false;
        }
        right--;
    }
    
    return true;
}
```
