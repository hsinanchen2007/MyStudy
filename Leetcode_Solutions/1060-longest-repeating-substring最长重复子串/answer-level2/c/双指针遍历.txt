```
int longestRepeatingSubstring(char *S)
{
    char *pos;
    char *start;
    int result = 0;
    int length = 0;

    if (strlen(S) == 1) {
        return 0;
    }

    while (*S != '\0') {
        start = S;
        pos = start + 1;
        while (*pos != '\0') {
            if (*start == *pos) {
                start++;
                pos++;
                length++;
                result = (length > result) ? length : result;
            } else {
                start = S;
                pos = pos - length + 1;
                length = 0;
            }
        }
        S++;
        length = 0;
    }
    return result;
}
```
