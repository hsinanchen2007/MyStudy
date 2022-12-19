```
bool is_number(char in)
{
    if (in >= '0' && in <= '9') {
        return true;
    }
    return false;
}

bool is_alpha(char in)
{
    if ((in >= 'a' && in <= 'z') || (in >= 'A' && in <= 'Z')) {
        return true;
    }
    return false;
}

bool is_same(char c1, char c2)
{
    if ((c1 - c2) == 0) {
        return true;
    }

    if (is_number(c1) | is_number(c2)) {
        return false;
    }

    if (c1 > c2) {
        if ((c1 - c2) == 32) {
            return true;
        }
    } else {
        if ((c2 - c1) == 32) {
            return true;
        }
    }
    return false;
}

bool isPalindrome(char * s){
    if (s == NULL || *s == '\0') {
        return true;
    }

    int end = strlen(s) - 1;
    int start = 0;

    while (start <= end) {
        if (!is_number(s[start]) && !is_alpha(s[start])) {
            start++;
            continue;
        }

        if (!is_number(s[end]) && !is_alpha(s[end])) {
            end--;
            continue;
        }

        if (!is_same(s[start], s[end])) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
```
