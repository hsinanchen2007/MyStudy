### 解题思路
此处撰写解题思路

### 代码

```c
#define INDEX_NUM 26

typedef struct tagWordDictory{
    struct tagWordDictory *next[INDEX_NUM];
    bool isString;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    int i = 0;
    WordDictionary *node = (WordDictionary *)malloc(sizeof(WordDictionary));

    node->isString = false;
    while (i < INDEX_NUM) {
        node->next[i++] = NULL;
    }
    return node;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    int i, index;
    WordDictionary *node = NULL;

    if (obj == NULL) {
        return;
    }
    node = obj;

    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] < 'a' || word[i] > 'z') {
            continue;
        }
        index = word[i] - 'a';
        if (node->next[index] == NULL) {
            node->next[index] = wordDictionaryCreate();
        }
        node = node->next[index];
    }
    node->isString = true;
    
    return;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    int i, index;
    int j = 0;
    WordDictionary *node = NULL;
    int isExist = false;

    if (obj == NULL) {
        return false;
    }
    node = obj;
    
    for (i = 0; word[i] != '\0'; i++) {
        while (word[i] == '.') {
            if (true == wordDictionarySearch(node->next[j++], &word[i+1])) {
                return true;
            }
            if (j >= INDEX_NUM) {
                return false;
            }
        }
        index = word[i] - 'a';
        if (node->next[index] == NULL) {
            return false;
        }
        node = node->next[index];
    }

    return node->isString;
}

void wordDictionaryFree(WordDictionary* obj) {
    int i, index;
    WordDictionary *nodeLast = NULL;
    WordDictionary *node = NULL;

    if (obj == NULL) {
        return;
    }
    for (i = 0; i < INDEX_NUM; i++) {
        wordDictionaryFree(obj->next[i]);
    }
    free(obj);

    return;
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
```