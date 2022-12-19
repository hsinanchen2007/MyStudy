C语言解法

```
char *simplifyPath(char * path){

    char *retStr = (char *)malloc(sizeof(char) * 1000);
    *retStr = '\0';

    char a[200][100];
    memset(a, 0, sizeof(a));
    int index1 = 0;
    int index2 = 0;

    while(*path != '\0') {
        if(*path == '/') {
            path++;
            continue;
        }

        index2 = 0;
        while(*path != '/' && *path != '\0') {
            a[index1][index2] = *path;
            index2++;
            path++;
        }
        a[index1][index2] = '\0';
        index1++;
    }

    int i = 0;

    int result[100] = {0};
    int index = 0;

    for(i = 0; i<index1; i++) {
        if(strcmp(a[i], "..") == 0 && index < 1) {
            continue;
        } else if(strcmp(a[i], "..") == 0) {
            result[index] = 0;
            index--;
        } else if(strcmp(a[i], ".") == 0) {
            continue;
        } else {
            result[index] = i;
            index++;    
        }      
    }

    if(index != 0) {
        for(i = 0; i<index; i++) {
        strcat(retStr, "/");
        strcat(retStr, a[result[i]]);
        }
    } else {
        return "/";
    }

    return retStr;
}
```
