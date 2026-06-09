```
bool isPalindrome(char *s)
{
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i < j)
    {
        char a = tolower(s[i]);
        if (!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'))
        {
            i++;
            continue;
        }
        char b = tolower(s[j]);
        if (!(s[j] >= '0' && s[j] <= '9' || s[j] >= 'a' && s[j] <= 'z'))
        {
            j--;
            continue;
        }
        if (a != b)
            return false;
        i++;
        j--;
    }
    return true;
}
```
