利用数组完成统计，提取最多的偶数然后加上1（如果有的话）即可
```
int longestPalindrome(char * s){
    int i;
    int len = strlen(s);
    int hash[52] = {0};
    for (i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            hash[s[i] - 'a']++;
        } else {
            hash[26 + s[i] - 'A']++;
        }
    }
    int count = 0;
    int odd = 0;
    for (i = 0; i < 52; i++) {
        if (hash[i] % 2 == 0) {
            count += hash[i];
        } else {
            count += hash[i] - 1;
            odd = 1;
        }
    }
    count += odd;
    return count;
}
```
