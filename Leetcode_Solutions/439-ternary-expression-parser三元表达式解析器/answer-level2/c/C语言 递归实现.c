```
char * parseTernary(char * expression){
    char *a = strstr(expression, "?");
    char *b = strstr(expression, ":");
    if (a == NULL || a > b) { 
        char *str = strstr(expression, ":");
        if (str != NULL) {
            *str = 0;
        }
        return expression;
    } 
    if (expression[0] == 'F') {
        int i;
        int k = 0;
        for (i = 0; i < strlen(expression); i++) {
            if (expression[i] == '?') {
                k++;
            } 
            if (expression[i] == ':') {
                if (--k == 0) {
                    break;
                }
            }
        }
        return parseTernary(expression + i + 1);
    }
    return parseTernary(expression + 2);

    return NULL;    
}
```
