```
int numDecodings(char * s){
    if (s[0] == '\0') {
        return 1;
    } else if (s[0] == '0') {
        return 0;
    }
    if (s[0] != '\0' && s[1] != '\0') {
        int a = s[0] - '1' + 1;
        int b = s[1] - '1' + 1;
        int c = a * 10 + b;
        if (c <= 26) {
            return numDecodings(s + 1) + numDecodings(s + 2);
        }
    }
    return numDecodings(s + 1);
}
```
