### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_NUM     10001
#define MAX_TMP     20

typedef struct {
    char data[MAX_NUM];
    int num[MAX_NUM];
    int size;
    int pos;
} StringIterator;

int GetNextChar(int pos, char *str, StringIterator *obj)
{
    char ch = 0;
    if ((str[pos] >= 'a' && str[pos] <= 'z') || (str[pos] >= 'A' && str[pos] <= 'Z')) {
        ch = str[pos];
    }
    int start = pos + 1;
    int end = 0;
    for (int i = start; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            end = i - 1;
            break;
        }
        if (i == strlen(str) - 1) {
            end = i;
        }
    }
    char tmp[MAX_TMP] = {0};
    for (int j = 0; j < (end - start + 1); j++) {
        tmp[j] = str[start + j];
    }
    int num = atoi(tmp);
    obj->data[obj->size] = ch;
    obj->num[obj->size] = num;
    obj->size += 1;
    return end;
}

StringIterator* stringIteratorCreate(char * compressedString) {
    StringIterator *obj = (StringIterator *)malloc(sizeof(StringIterator));
    if (obj == NULL) {
        return obj;
    }
    for (int i = 0; i < MAX_NUM; i++) {
        obj->data[i] = 0;
    }
    for (int i = 0; i < MAX_NUM; i++) {
        obj->num[i] = 0;
    }
    obj->size = 0;
    obj->pos = 0;
    if (!compressedString || strlen(compressedString) == 0) {
        return obj;
    }
    for (int i = 0; i < strlen(compressedString); i++) {
        i = GetNextChar(i, compressedString, obj);
    }
    return obj;
}

char stringIteratorNext(StringIterator* obj) {
    char ch = ' ';
    if (obj->pos >= obj->size) {
        return ch;
    }
    if (obj->num[obj->pos] > 0) {
        ch = obj->data[obj->pos];
        obj->num[obj->pos] -= 1;
        if (obj->num[obj->pos] == 0) {
            obj->pos += 1;
        }
        return ch;
    }
    return ch;
}

bool stringIteratorHasNext(StringIterator* obj) {
    if (obj->pos >= obj->size) {
        return false;
    }
    if (obj->num[obj->pos] > 0) {
        return true;
    } else {
        return false;
    }
}

void stringIteratorFree(StringIterator* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/
```