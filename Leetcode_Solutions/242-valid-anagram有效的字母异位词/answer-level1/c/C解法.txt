```
bool isAnagram(char * s, char * t){
    if (s == NULL || t == NULL || strlen(s) != strlen(t)) {
        return false;
    }

    char count1[128]={0};
    char count2[128]={0};

    int i = 0;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
        count1[s[i]]++;
        count2[t[i]]++;
    }

    for (i = 0; i < 128; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }

    return true;
}
```
