
```
int char_value[128];
bool isPalindrome(char * s){
    for (int i = 0; i < 128; ++i) {
        if ((48 <= i && i <= 57) || 
            (65 <= i && i <= 90) || 
            (97 <= i && i <= 122)) char_value[i] = 0;
        else char_value[i] = 1;
    }
    int low = 0;
    int hig = strlen(s) - 1;
    while (low < hig) {
        while (char_value[s[low]] && low < hig) ++low;
        while (char_value[s[hig]] && low < hig) --hig;
        if( (s[low] != s[hig]) && s[low] != (s[hig] ^ 0x20) ) return false;
        ++low, --hig;
    }
    return true;
}
```
