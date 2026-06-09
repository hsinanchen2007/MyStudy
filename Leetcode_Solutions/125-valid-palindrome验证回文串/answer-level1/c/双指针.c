```
// 双指针
bool IsEffective(char c) {
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ) {
        return true;
    } else {
        return false;
    }
}

char ToLower(char c) {
    char res = '0';
    if( (c >= 'a' && c <= 'z' ) || (c >= '0' && c <= '9')) {
        res = c;
    } else if((c >= 'A' && c <= 'Z')) {
        res = c + 32;
    }
    return res;
}
bool isPalindrome(char * s){
    int length = strlen(s);
    int i = 0;
    int j = length - 1;
    while(i < j) {
        char ci = '0';
        char cj = '0';
        if(IsEffective(s[i])) {
            ci = ToLower(s[i]);
        } else {
            i++;
            continue;
        }
        if(IsEffective(s[j])) {
            cj = ToLower(s[j]);
        } else {
            j--;
            continue;
        }
        if(ci != cj) {
            return false;
        } else {
            i++;
            j--;
        }
        
    }
    return true;
}
```
