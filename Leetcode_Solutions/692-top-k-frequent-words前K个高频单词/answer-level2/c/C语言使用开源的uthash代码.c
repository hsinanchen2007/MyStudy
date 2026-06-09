```
#include <string.h>
typedef struct hash_node {
    char key[100];
    int count;
    UT_hash_handle hh;
} Hash_Node; 
Hash_Node *g_head = NULL;
int my_compare(Hash_Node* a, Hash_Node* b)
{
    if (a->count != b->count) {
       return b->count - a->count;
    }
    return strcmp(a->key, b->key);
}
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    g_head = NULL;
    int i;
    for (i = 0; i < wordsSize; i++) {
        Hash_Node *my_add = NULL;
        HASH_FIND_STR(g_head, words[i], my_add);
        if (my_add == NULL) {
            my_add = (Hash_Node*)malloc(sizeof(Hash_Node));
            strcpy(my_add->key, words[i]);
            my_add->count = 1;
            HASH_ADD_STR(g_head, key, my_add);
        } else {
            my_add->count++;
        }
    }

    HASH_SORT(g_head, my_compare);

    *returnSize = k;
    char **res = (char*)malloc(sizeof(char*) * k);
    i = 0;
    Hash_Node *my_user = NULL;
    Hash_Node *my_temp = NULL;
    HASH_ITER(hh, g_head, my_user, my_temp) {
        if (i < k) {
            res[i] = (char*)malloc(sizeof(char) * 100);
            strcpy(res[i++], my_user->key);
        }
    }

    return res;
}
```
