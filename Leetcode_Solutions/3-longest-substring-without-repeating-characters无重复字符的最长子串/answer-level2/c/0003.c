```
int notRepeat(char *s, int begin, int end) {
    for (int i = begin; i < end + 1; i++) {
        for (int j = i + 1; j < end + 1; j++) {
            if (s[i] == s[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int updateMaxIfNeed(int max, int begin, int end) {
    return max > (end - begin + 1) ? max : (end - begin + 1);
}

int lengthOfLongestSubstring(char *s) {
    int max = 0;
    for (int i = 0; i < strlen(s) - max; i++) {
        for (int j = i + max; j < strlen(s); j++) {
            if (notRepeat(s, i, j)) {
                max = updateMaxIfNeed(max, i, j);
            } else {
                break;
            }
        }
    }
    return max;
}
```
