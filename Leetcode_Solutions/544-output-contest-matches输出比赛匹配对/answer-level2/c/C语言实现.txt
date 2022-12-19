```
char group[4097][50000];
char * findContestMatch(int n)
{
    int i, len, mid, r, j, k, x;
    char tmp[50000];
    for (i = 1; i <= n; i++) {
        mid = i;
        j = 0;
        while (mid > 0) {
            r = mid % 10;
            tmp[j] = r + '0';
            j++;
            mid = mid / 10;
        }
        x = 0;
        for (k = j - 1; k >= 0; k--) {
            group[i][x] = tmp[k];
            x++;
        }
        group[i][x] = '\0';
    }
    while (n > 0) {
        for (i = 1; i <= n / 2; i++) {
            tmp[0] = '(';
            tmp[1] = '\0';
            strcat(tmp, group[i]);
            len = strlen(tmp);
            tmp[len] = ',';
            tmp[len + 1] = '\0';
            strcat(tmp, group[n + 1 - i]);
            len = strlen(tmp);
            tmp[len] = ')';
            tmp[len + 1] = '\0';
            strcpy(group[i], tmp);
        }
        n = n / 2;
    }
    return group[1];
}
```
