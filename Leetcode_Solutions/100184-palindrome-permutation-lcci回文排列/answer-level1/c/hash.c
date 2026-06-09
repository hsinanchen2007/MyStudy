```
bool canPermutePalindrome(char * s){
    int arr[58] = {0};

    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            arr[s[i] - 'A']++;
        }
    }

    for (int i = 0; i < 58; i++) {
        printf("%d ", arr[i]);
    }
    int flag = 0;

    for (int i = 0; i < 58; i++) {
        if (flag == 2) {
            return false;
        }
        if (arr[i] % 2 == 1) {
            flag++;
        }
    }
    return true;
}
```
