**双指针法，遇到元音字母交换即可。**
```c
int vowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    else
        return 0;
}

char * reverseVowels(char * s){
    int i = 0, j = strlen(s) - 1;
    char t;
    while(i < j){
        while(i < j && !vowel(s[i]))
            i++;
        while(i < j && !vowel(s[j]))
            j--;
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
    return s;
}
```