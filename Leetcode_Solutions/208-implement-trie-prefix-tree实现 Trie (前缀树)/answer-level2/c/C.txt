### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_CHARACTOR_NUM 26

typedef struct tire_node{
    int count; /* 该节点的单次数量 */
    struct tire_node* child[MAX_CHARACTOR_NUM];
} Trie;

/** Initialize your data structure here. */

Trie* allocTrieNode()
{
    Trie* obj = (Trie *)malloc(sizeof(Trie));
    if (obj == NULL) {
        return NULL;
    }
    obj->count = 0;
    for (int i = 0; i <  MAX_CHARACTOR_NUM; i++) {
        obj->child[i] = NULL;
    }
    return obj;
}

Trie* trieCreate() {
    return allocTrieNode();
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    char *p = word;
    Trie *node = obj;
    while (*p) {
        if (node->child[*p - 'a'] == NULL) {
            node->child[*p - 'a'] = allocTrieNode();
        }
        node = node->child[*p - 'a'];
        p++;
    }
    node->count++;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    char *p = word;

    while (*p && node != NULL) {
        node = node->child[*p - 'a'];
        p++;
    }

    if (node == NULL) {
        return false;
    } else {
        return (node->count > 0 ? (true) : (false));
    }
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    char *p = prefix;

    while (*p && node != NULL) {
        node = node->child[*p - 'a'];
        p++;
    }

    return (node == NULL ? (false) : (true));
}

/* 释放内存代码更新 */
void trieFree(Trie* obj) {
    if (obj != NULL ) {
        for (int i = 0; i < MAX_CHARACTOR_NUM; i++) {
            if (obj->child[i] != NULL) {
                trieFree(obj->child[i]);
            }
        }
    }
    free(obj);
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
```