1、每个单词按照相对第一个字母的差值，生成新的字符串，如xyz和abc,都可以生成 #1#2#。差值如果有负值需要加上26.
2、把原单词和转换后的放在一个结构体中，按转换后的字符串进行快排，同一组的就连在一起了，简单整理一下输出就行，C语言的三重指针输出比较麻烦。
```
#define MAX_SIZE 10000
 struct Str {
     char *string;
     char *change;
 };
struct Str str[MAX_SIZE] = {0};
 int Comp(void *a, void *b) {
     struct Str *x = a;
     struct Str *y = b;
     return strcmp((*x).change, (*y).change);
 }
 void GetChange(char **strings, int stringsSize) {
    for (int i = 0; i < stringsSize; i++) {
        str[i].string = strings[i];
        str[i].change = (char*)malloc((strlen(strings[i]) * 2) * sizeof(char**));
        if (str[i].change == NULL) {
            return NULL;
        }
        memset(str[i].change, 0, (strlen(strings[i]) * 2) * sizeof(char**));
        str[i].change[0] = '#';
        int k = 1;
        for (int j = 1; j < strlen(strings[i]); j++) {
            int x = strings[i][j] - strings[i][0];
            if (x < 0) {
                x += 26;
            }
            sprintf(&str[i].change[k], "%d%c", x, '#');
            while (str[i].change[k] != 0) {
                k++;
            }
        }
    }
    qsort(str, stringsSize, sizeof(struct Str), Comp);
    return;
 }
char *** groupStrings(char ** strings, int stringsSize, int* returnSize, int** returnColumnSizes){
    if (stringsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    memset(str, 0, MAX_SIZE * sizeof(struct Str));
    char ***result = (char***)malloc(stringsSize * sizeof(char**));
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, stringsSize * sizeof(char**));
    returnColumnSizes[0] = (int*)malloc(stringsSize * sizeof(int));
    GetChange(strings, stringsSize);
    
    int index = 0;
    int begin = 0;
    int end = 0;
    for (int i = 1; i < stringsSize; i++) {
        if (strcmp(str[i].change, str[i - 1].change) == 0) {
            continue;
        }
        end = i;
        result[index] = (char**)malloc((end - begin) * sizeof(char*));
        if (result[index] == NULL) {
            return NULL;
        }
        memset(result[index], 0, (end - begin) * sizeof(char*));
        int k = 0;
        for (int j = begin; j < end; j++) {
            result[index][k++] = str[j].string;
        }
        returnColumnSizes[0][index] = k;
        index++;
        begin = i;
    }
    end = stringsSize;
    result[index] = (char**)malloc((end - begin) * sizeof(char*));
    if (result[index] == NULL) {
        return NULL;
    }
    memset(result[index], 0, (end - begin) * sizeof(char*));
    int k = 0;
    for (int j = begin; j < end; j++) {
        result[index][k++] = str[j].string;
    }
    returnColumnSizes[0][index] = k;
    index++;
    *returnSize = index;
    return result;
}
```
