```
int strStr(char * haystack, char * needle){
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 == 0) {
        return 0;
    }
    int l = 0;
    int h = 0;
    while (h < len1) {
        for (int i = l; i < len1; i++) {
            if (haystack[i] == needle[h - l]) {
                h++;
            } else {
                l++;
                h = l;
                break;
            }
            if (h - l == len2) {
                return l;
            }
        }
    }
    return -1;
}
```
