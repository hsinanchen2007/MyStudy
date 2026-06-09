```
bool isOneEditDistance(char * s, char * t)
{
    int len1, len2, i, j, num;
    len1 = strlen(s);
    len2 = strlen(t);
    if (abs(len1 - len2) > 1) {
        return false;
    }
    if (strcmp(s, t) == 0) {
        return false;
    }
    if (len1 == len2) {
        num = 0;
        for (i = 0; i < len1; i++) {
            if (s[i] != t[i]) {
                num++;
            } 
            if (num > 1) {
                return false;
            }
        }
        return true;
    } else {
        i = 0; 
        j = 0;
        num = 0;
        while (i < len1 && j < len2) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                if (num > 0) {
                    break;
                }
                if (len1 > len2) {
                    i++;
                    num++;
                } else {
                    j++;
                    num++;
                }
            }
        }
        if (i == len1 || j == len2) {
            return true;
        } else {
            return false;   
        }
    }
}
```
