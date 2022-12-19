```
bool isValid(char * s){
    if (strlen(s) == 0)
        return true;
    char temp[10001];
    int i;
    int count = 0;
    int len = strlen(s);
    for (i = 0; i < len; i++) {
        if (s[i] == ')') {
            if (count == 0)
                return false;
            if (temp[count - 1] == '(') {
                count--;
                continue;
            }
            temp[count] = ')';
            count++;
            continue;   
        }
        if (s[i] == ']') {
            if (count == 0)
                return false;
            if (temp[count - 1] == '[') {
                count--;
                continue;
            }
            temp[count] = ']';
            count++;
            continue;   
        }
        if (s[i] == '}') {
            if (count == 0)
                return false;
            if (temp[count - 1] == '{') {
                count--;
                continue;
            }
            temp[count] = '}';
            count++;
            continue;   
        }
        temp[count] = s[i];
        count++;
    }
    if (count == 0)
        return true;
    return false;
}
```
