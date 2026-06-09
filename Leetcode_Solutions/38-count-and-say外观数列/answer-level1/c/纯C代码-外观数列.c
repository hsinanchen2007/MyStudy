### 解题思路
此处撰写解题思路

### 代码

```c
void nextStr(char *data1, char **data2) {
    int num = 0;
    int i;
    int k = 0;
    for (i = 0; data1[i] != '\0'; i++) {
        num++;
        if (data1[i] != data1[i+1]) {
            (*data2)[k++] = num + '0';
            (*data2)[k++] = data1[i];
            num = 0;
        }
    }
    (*data2)[k] = '\0';

    return;
}

char * countAndSay(int n){
    char *data1 = (char *)calloc(1, sizeof(char) * 5000);
    char *data2 = (char *)calloc(1, sizeof(char) * 5000);
    char *tmp = NULL;
    int i;
    
    data1[0] = 1 + '0';

    for (i = 2; i <= n; i++) {
        nextStr(data1, &data2);
        tmp = data1;
        data1 = data2;
        data2 = tmp;
    }
    free(data2);

    return data1;
}
```