``` c
bool isVowel(char c){
    return 'a'== c||'e'==c||'i'==c||'o'==c||'u'== c||'A'==c||'E'==c||'I'==c||'O'==c||'U'==c;
}

void swap(char *c1, char *c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

char *reverseVowels(char *s){
    int i = 0, j = strlen(s)-1;
    while(i<j){
        if(!isVowel(s[i])) i++;
        else if(!isVowel(s[j])) j--;
        else swap(&s[i++], &s[j--]);
    }
    return s;
}
```
