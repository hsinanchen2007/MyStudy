```
bool Find(char *s)
{
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                return true;
            }
        }
    }
    return false;
}

bool buddyStrings(char * A, char * B)
{
    int len1 = strlen(A);
    int len2 = strlen(B);
    int tag[100 * 1024] = {0};
    int total = 0;

    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (A[i] != B[i]) {
            tag[total++] = i;
        }
    }
    if (total == 2) {
        printf("AB is 2 diff, tag[0]=%d, tag[2]=%d\n", tag[0], tag[1]);
        if (A[tag[0]] == B[tag[1]] && A[tag[1]] == B[tag[0]]) {
            return true;
        }
    }
    if (total == 0) {
        printf("AB is same\n");
        if (Find(A)) {
            return true;
        }
    }
    return false;
}
```
