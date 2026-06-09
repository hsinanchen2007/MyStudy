```
int strStr(string haystack, string needle) {
    if(haystack == "" && needle != "") return -1;
    if(needle == "") return 0;
    int pos = haystack.find(needle);
    if(pos < 0) return -1;
    else return pos;
}
```