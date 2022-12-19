bool isValid(char * s){
    if (s == NULL || strlen(s) == 0)
        return true;
    int len = strlen(s);
    if (len%2)
        return false;
    int i = 0;
    while (s[i]) {
        if ((s[i] == '(' && s[i + 1] == ')') ||
            (s[i] == '[' && s[i + 1] == ']') ||
            (s[i] == '{' && s[i + 1] == '}')) {
            memmove(s + i, s + i + 1 + 1, len + 1 - i - 2);
            return isValid(s);
        }
        i++;
    }
    return false;
}