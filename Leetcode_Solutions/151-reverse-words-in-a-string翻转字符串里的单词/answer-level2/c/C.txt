### 解题思路
此处撰写解题思路

### 代码

```c


char * reverseWords(char * s){
    if (s == NULL || strlen(s) == 0) {
        return "";
    } 
    char **temp = (char*)malloc(sizeof(char*) * 1000);
    int i;
    for (i = 0; i < 1000; i++) {
        temp[i] = (char*)malloc(sizeof(char) * 400);
    }
    char *p = strtok(s, " ");
    int count = 0;
    int len = 0;
    while (p) {
        len += strlen(p);
        strcpy(temp[count++], p);
        p = strtok(NULL, " ");
    }
    if (count <= 0) {
        return "";
    }
    for (i = 0 ; i < count; i++) {
        printf("%s\n", temp[i]);
    }

    char *res = (char*)malloc(sizeof(char) * (len + count));
    strcpy(res, temp[count - 1]);
    if (count - 2 < 0) {
        return res;
    }
    strcat(res, " ");
    for (i = count - 2; i >= 0; i--) {
        strcat(res, temp[i]);
        if (i == 0) {
            res[len + count - 1] = '\0';
        } else {
            strcat(res, " ");
        }
    }
    printf("%s\n", res);
    return res;
}


```