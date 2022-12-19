```
char * reverseWords(char * s){
    if (s == NULL) {
        return NULL;
    }
    int i = 0;
    char** res = (char**)calloc(strlen(s) + 1, sizeof(char*));
    char* result = (char*)calloc(100000, sizeof(char));
    char* token = NULL;
    token = strtok(s, " ");
    while (token != NULL) {
        res[i] = (char*)calloc(strlen(token) + 1, sizeof(char));
        strcpy(res[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    if (i == 0) {
        return "";
    }
    strcpy(result, res[i - 1]);
    if (i == 1) {
        return result;
    }
    strcat(result, " ");
    for (int j = i - 2; j >= 0; j--) {
        strcat(result, res[j]);
        if (j != 0) {
            strcat(result, " ");
        }
    }
    return result;
}
```
