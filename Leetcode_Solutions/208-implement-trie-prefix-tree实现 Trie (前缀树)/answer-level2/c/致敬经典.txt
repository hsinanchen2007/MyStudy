### 解题思路
此处撰写解题思路

### 代码

```c

#define NUM 26
typedef struct Trie_{
    bool isWord;
    struct Trie_ *nextList[NUM];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    memset(root, 0, sizeof(*root));
    return root; 
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *root = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int id = word[i] - 'a';
        //printf("%d %c %s\n", id, word[i], word);
        if (root->nextList[id] == NULL) {
            root->nextList[id] = trieCreate();
        }
        root = root->nextList[id];        
    }
    root->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *root = obj;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int id = word[i] - 'a';
        if (root->nextList[id] == NULL) {
            return false;
        }
        root = root->nextList[id];
    }
    return root->isWord;  
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *root = obj;
    int len = strlen(prefix);
    for (int i = 0; i < len; i++) {
        int id = prefix[i] - 'a';
        if (root->nextList[id] == NULL) {
            return false;
        }
        root = root->nextList[id];
    }
    return true;
}

void trieFree(Trie* obj) {
    Trie *root = obj;   
    for (int i = 0; i < NUM; i++) {        
        if (root->nextList[i] == NULL) {
            continue;
        }
        return trieFree(root->nextList[i]);
    }
    free(root);
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