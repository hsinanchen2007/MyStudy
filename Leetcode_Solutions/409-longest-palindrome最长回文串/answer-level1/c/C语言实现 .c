C语言实现
```C []
int longestPalindrome(char * s){
    int sum = 0, len = strlen(s), table[58] = {0};
    while (*s) table[(*s++) - 'A']++;
    for (int i = 0; i < 58; ++i) sum += table[i] & 0xfffffffe;
    return len > sum ? ++sum : sum;
}
```
