### 解题思路
UT_hash

### 代码

```c
typedef struct {
    int key;
    char value[1000];
    UT_hash_handle hh;
} HashData;

HashData *head = NULL;
HashData *charHead = NULL;

bool wordPattern(char * pattern, char * str)
{   
    head = NULL;
    charHead = NULL;
    int i;
    int len = strlen(pattern);
    const char declin[2] = " ";
    char *token = NULL;
    char temp[1000][1000] = { 0 };
    int index = 0;

    if (pattern == NULL && str == NULL) {
        return true;
    }
    HashData *ad = NULL;
    token = strtok(str, declin);
    while (token != NULL) {
        strcpy(temp[index++], token);
        token = strtok(NULL, declin);
    }
    if (index != len) {
        return false;
    }
    if (index == 1 && len == 1) {
        return true;
    }
    for (i = 0; i <len; i++) {
        HashData *s = NULL;
        int tempkey = pattern[i];
        HASH_FIND_INT(head, &tempkey, s);
        if (s != NULL && strcmp(s->value, temp[i]) != 0) {
            return false;
        }
        if (s == NULL) {
            ad = (HashData *)malloc(sizeof(HashData));
            ad->key = tempkey;
            strcpy(ad->value, temp[i]);
            HASH_ADD_INT(head, key, ad);
        }
    }
    for (i = 0; i <len; i++) {
        HashData *s = NULL;
        HASH_FIND_STR(charHead, temp[i], s);
        int tempkey = pattern[i];
        if (s != NULL && s->key != tempkey) {
            return false;
        }
        if (s == NULL) {
            ad = (HashData *)malloc(sizeof(HashData));
            ad->key = tempkey;
            strcpy(ad->value, temp[i]);
            HASH_ADD_STR(charHead, value, ad);
        }
    }
    return true;
}

```