### 解题思路
此处撰写解题思路

### 代码

```c
void strrev(char *p)
{
    int len = strlen(p);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        char tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;

        i++;
        j--;
    }
}

char * reverseWords(char * s){
    if (s == NULL || strlen(s) == 0) {
        return s;
    }

    char *res = calloc(strlen(s) + 2, sizeof(char));
    char *p = strtok(s, " ");
    while (p) {
        strrev(p);
        strcat(res, p);
        strcat(res, " ");
        p = strtok(NULL, " ");
    }

    if (strlen(res)) {
        res[strlen(res) - 1] = '\0';
    }
    
    strrev(res);
    return res;
}
```