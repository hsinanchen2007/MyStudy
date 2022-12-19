int CenterSpan(char *s, int i, int j) 
{
    int sLen;
    int k, minLen;
    sLen = strlen(s);
    minLen = (i + 1) > (sLen - j) ? (sLen - j)  : (i + 1);
    for (k = 0; k  < minLen; k++) {
        if (s[i - k] != s[j + k]) {
            break;
        }
    }
    if (i == j) {
        return k == 0 ? 1 : (2 * k - 1);
    } else {
        return k == 0 ? 0 : 2 * k;
    }     
}

char * longestPalindrome(char * s){
    int sLen;
    int i;
    int len1, maxLen1 = 0;
    int len2, maxLen2 = 0;
    int start1, start2;
    char *ans;

    if ((!s) || (*s == '\0')) { return s; }
    
    sLen = strlen(s);
    if (sLen == 1) { return s; }

    ans = (char*)malloc(sLen + 1);
    if (!ans) { return NULL; }
    memset(ans, 0, sLen + 1);

    for (i = 1; i < sLen; i++) {
        len1 = CenterSpan(s, i, i);
        if (maxLen1 < len1) {
            start1 = i - len1 / 2;
            maxLen1 = len1;
        }
    }

    for (i = 0; i < sLen - 1; i++) {
        len2 = CenterSpan(s, i, i + 1);
        if (maxLen2 < len2) {
            start2 = i + 1 - len2 / 2;
            maxLen2 = len2;
        }
    }
    
    if (maxLen1 <= maxLen2) {
        strncpy(ans, s + start2, maxLen2);
    } else {
        strncpy(ans, s + start1, maxLen1);
    }
    return ans;
}