![image.png](https://pic.leetcode-cn.com/8a3fa8f501e3802ce16f546245002bf43cc8413b4a5a06e968b14ee78612a5ab-image.png)



bool isPair(char s1, char s2)
{
    if (s1 == '(' && s2 == ')') {
        return true;
    }

    if (s1 == '[' && s2 == ']') {
        return true;
    }

    if (s1 == '{' && s2 == '}') {
        return true;
    }

    return false;
}

bool isValid(char *s)
{
    int len = strlen(s);
    if (len == 0) {
        return true;
    }
    char *string = (char*)malloc(len * sizeof(char));
    int sIndex = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            string[sIndex] = s[i];
            sIndex++;
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (sIndex == 0) {
                free(string);
                return false;
            } else if (isPair(string[sIndex-1], s[i])) {                
                sIndex--;
                string[sIndex] = 0;
            } else {
                free(string);
                return false;
            }
        }
    }
    if (sIndex == 0) {
        free(string);
        return true;
    }
    free(string);
    return false;
}