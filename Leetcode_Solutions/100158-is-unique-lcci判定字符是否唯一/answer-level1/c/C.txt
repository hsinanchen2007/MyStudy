```
bool isUnique(char* astr){
    int arr[26];

    memset(arr, 0, sizeof(int) * 26);
    
    for (int i = 0; i < strlen(astr); i++) {
        if (arr[astr[i] - 'a'] > 0) {
            return false;
        }
        arr[astr[i] - 'a']++;
    }

    return true;
}
```
