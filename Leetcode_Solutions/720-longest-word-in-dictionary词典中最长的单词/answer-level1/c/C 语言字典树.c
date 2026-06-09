```
struct trie_node {
    bool is_end;
    struct trie_node *child[26];
};

static struct trie_node *create()
{
    struct trie_node *node = malloc(sizeof(struct trie_node));
    node->is_end = false;
    for (int i = 0; i < 26; i++) {
        node->child[i] = NULL;
    }
    return node;
}

static void insert_word(struct trie_node *obj, char *word)
{
    while (*word) {
        if (obj->child[*word - 'a'] == NULL) {
            obj->child[*word - 'a'] = create();
        }
        obj = obj->child[*word - 'a'];
        word++;
    }
    obj->is_end = true;
}

static bool is_inc_word(struct trie_node *obj, char *word)
{
    while (*word) {
        if (obj->child[*word - 'a'] == NULL)
            return false;
        else if (obj->child[*word - 'a']->is_end == false)
            return false;
        
        obj = obj->child[*word - 'a'];
        word++;
    }
    return obj->is_end;
}

static void free_trie(struct trie_node *obj)
{
    for (int i = 0; i < 26; i++) {
        if (obj->child[i] != NULL) {
            free_trie(obj->child[i]);
        }
    }
    free(obj);
}

char * longestWord(char ** words, int wordsSize){
    struct trie_node *root = create();
    for (int i = 0; i < wordsSize; i++) {
        insert_word(root, words[i]);
    }
    char *ret = malloc(sizeof(char) * 31);
    memset(ret, 0, sizeof(char) * 31);

    for (int i = 0; i < wordsSize; i++) {
        if (is_inc_word(root, words[i])) {
            if (strlen(words[i]) > strlen(ret))
                strcpy(ret, words[i]);
            else if (strlen(words[i]) == strlen(ret) && strcmp(words[i], ret) == -1)
                strcpy(ret, words[i]);
        }
    }

    return ret;
}
```
