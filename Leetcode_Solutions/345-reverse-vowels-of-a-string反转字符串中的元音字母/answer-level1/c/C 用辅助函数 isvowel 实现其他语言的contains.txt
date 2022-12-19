  就是快排的一次遍历

```
inline
bool isvowel(char c) {
    const char * const vowels = "aeiouAEIOU";
    for (int i = 0; vowels[i] != '\0'; ++i)
        if (c == vowels[i])
            return true;
    return false;
}

char * reverseVowels(char * s){
    if (!s)
        return NULL;
    int i = 0; int j = strlen(s)-1;
    while (i < j) {
        while (i < j && !isvowel(s[j]))
            --j;
        while (i < j && !isvowel(s[i]))
            ++i;
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
    return s;
}
```
