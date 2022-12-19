![8FE0DA78-7A72-4E1E-9C98-837482E1587F.jpeg](https://pic.leetcode-cn.com/37352249ea748072ce28301acf317bf55841c4b008ac5661173d50cc5688028c-8FE0DA78-7A72-4E1E-9C98-837482E1587F.jpeg)

```
bool isPalindrome(char * s)
{
    if (s == NULL) {
        return true;
    }
    int l;
    int m;
    l = 0;
    m = strlen(s) - 1;

    while (l < m) {
        if ((s[l] >= 'A') && (s[l] <= 'Z')) {
            s[l] = s[l] +'a' - 'A';
        } else {
            if (!(((s[l] >= 'a') && (s[l] <= 'z')) ||
                ((s[l] >= '0') && (s[l] <= '9')))) {
                    l++;
                    continue;
                }
        }
        if ((s[m] >= 'A') && (s[m] <= 'Z')) {
            s[m] = s[m] +'a' - 'A';
        } else {
            if (!(((s[m] >= 'a') && (s[m] <= 'z')) ||
                ((s[m] >= '0') && (s[m] <= '9')))) {
                    m--;
                    continue;
                }
        }
        //printf("s[l]: %c, s[m]: %c\n", s[l], s[m]);
        if (s[l] != s[m]) {
            return false;
        }
        l++;
        m--;
    }
    return true;
}
```
