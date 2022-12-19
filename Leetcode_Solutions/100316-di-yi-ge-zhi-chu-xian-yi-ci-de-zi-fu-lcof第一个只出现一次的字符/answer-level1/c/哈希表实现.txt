```
char firstUniqChar(char* s){
    if (s == "") {
        return ' ';
    }
    int* arr = (int *)malloc(sizeof(int) * 26);
    memset(arr, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(s); i++) {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (arr[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
    return ' '; 
}
```
