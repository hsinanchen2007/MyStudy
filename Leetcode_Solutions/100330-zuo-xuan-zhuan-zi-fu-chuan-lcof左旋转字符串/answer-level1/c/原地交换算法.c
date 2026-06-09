emm看了半天好像没有人提到reverse的那种方法。
```
void swap(char *s, int i, int j){
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}
void reverse(char *s, int lo, int hi){
   for(;lo < hi; lo++, hi--){
       swap(s, lo, hi);
   }
}
char* reverseLeftWords(char* s, int n){
    int len = 0;
    for(;s[len] != '\0'; len++);
    n %= len;
    reverse(s, 0, len - 1);
    reverse(s, 0, len - n - 1);
    reverse(s, len - n, len - 1);
    return s;
}
```