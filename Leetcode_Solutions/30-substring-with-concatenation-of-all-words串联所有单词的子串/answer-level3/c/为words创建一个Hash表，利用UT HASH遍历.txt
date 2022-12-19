### 解题思路
为words创建一个Hash表，利用UT HASH遍历。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hash_node{
     char *key;
     int value;
     int find;
     struct UT_hash_handle hh;
};
struct hash_node *g_users = NULL;
int result[1024] = {0};
int hash_add_node(char *key, int len)
{
    struct hash_node *local;
    HASH_FIND_STR(g_users, key, local);
    if (local == NULL) {
        local = (struct hash_node *)malloc(sizeof(struct hash_node));
        local->key = malloc(sizeof(char) * (len + 1));
        strncpy(local->key, key, len + 1);
        local->find = 0;
        local->value = 1;
        HASH_ADD_STR(g_users, key, local);
    }
    else {
        local->value++;
    }
    
    //printf("len:%d, key:%s\n", len, local->key);
    return local->value;
}
bool is_true(void)
{
    struct hash_node *current_user, *tmp;
    HASH_ITER(hh, g_users, current_user, tmp) {
        if (current_user->value != current_user->find) {
            return false;
        }
    }
    return true;
}

void hash_clear_find(void)
{
    struct hash_node *current_user, *tmp;
    HASH_ITER(hh, g_users, current_user, tmp) {
        current_user->find = 0;
    }
    return ;
}

void deleteAll(void) {
    struct hash_node *current, *tmp;
    HASH_ITER(hh, g_users, current, tmp) {
        HASH_DEL(g_users, current);
        free(current);
    }
}
void hash_find_node(char *key, int len)
{
    struct hash_node *local;
    HASH_FIND_STR(g_users, key, local);

    if (local) {
        (local->find)++;
        return ;
    }
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int i, j;
    int s_len;
    int w_len;
    char temp;

    g_users == NULL;
    memset(result, 0, sizeof(int)*1024);
    *returnSize = 0;

    if (s == NULL || words == NULL || wordsSize == 0) {
        return NULL;
    }

    s_len = strlen(s);
    w_len = strlen(words[0]);
    for (i = 0; i < wordsSize; i++) {
        hash_add_node(words[i], w_len);
    }

    for (i = 0; i <= s_len - (w_len * wordsSize); i++) {
        for(j = 0; j < wordsSize; j++) {
            temp = s[i + (j + 1) * w_len];
            s[i + (j + 1) * w_len] = '\0';
            hash_find_node(s + i + (j * w_len), w_len);
            s[i + (j + 1) * w_len] = temp;
        }
        if (is_true()) {
            result[*returnSize] = i;
            (*returnSize)++;
            //printf("i:%d\n", i);  
        }
        hash_clear_find();
    }

    deleteAll();
    //printf("returnSize:%d , result[0]:%d, result[1]:%d \n", *returnSize, result[0], result[1]);
    return result;
}

```