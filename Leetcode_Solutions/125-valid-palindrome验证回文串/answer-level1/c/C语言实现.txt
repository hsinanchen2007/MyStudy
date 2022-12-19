C语言实现
```C []
bool isPalindrome(char * s){
    int len = strlen(s);
    if (0 == len) return true;
    char table[255] = {0};
    int i, j;
    for (i = 'A'; i <= 'Z'; ++i){
        table[i] = i;
        table[i + 32] = i;
    }
    for (i = '0'; i <= '9'; ++i){
        table[i] = i;
    }
    i = 0, j = len - 1;
    while (i < j) {
        while (0 == table[s[i]] && i <= j) ++i;
        while (0 == table[s[j]] && i <= j) --j;
        if (i < j && table[s[i++]] != table[s[j--]]) return false;
    }
    return true;
}
```
