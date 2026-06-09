```

#define maxSize 1000
int processVersion(int* a, char* version) 
{
    int index = 0;
    char* str = (char*)malloc(sizeof(char) * 10);
    str = strtok(version, ".");
    while (str != NULL) {
        a[index++] = atoi(str);
        str = strtok(NULL, ".");
    }

    return index;
}
int compareVersion(char * version1, char * version2){
    int ver1[maxSize] = {0};
    int ver2[maxSize] = {0};
    int len1 = processVersion(ver1, version1);
    int len2 = processVersion(ver2, version2);
    int i = 0;
    while (i < len1 && i < len2) {
        if (ver1[i] > ver2[i]) {
            return 1;
        } else if (ver1[i] < ver2[i]) {
            return -1;
        }
        i++;
    }
    if (i == len1 && i == len2) {
        return 0;
    } else if (i < len1) {
        while (i < len1) {
            if (ver1[i] > 0) {
                return 1;
            }
            i++;
        }
    } else if (i < len2) {
        while (i < len2) {
            if (ver2[i] > 0) {
                return -1;
            }
            i++;
        }
    }

    return 0;
}
```
