```
bool CheckPermutation(char* s1, char* s2)
{
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int arr[26];
    int arrBak[26];
    memset(arr, 0, sizeof(int) * 26);
    memset(arrBak, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(s1); i++) {
        arr[s1[i] - 'a']++;
        arrBak[s2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] != arrBak[i]) {
            return false;
        }
    }
    return true;
}
```
