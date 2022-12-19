### 解题思路
第一次听说前缀树，就像查字典一样，先查第一个字母，在第一个字母的map数组中找第二个字母，在第二个字母的map数组中找第3个......
如果这个字母是结尾，cnt不为0.
如果一个字母后面是 '.', 则遍历这个字母的map数组，任何一个字母满足都可以。这里需要dfs。

### 代码

```c
typedef struct node {
    int cnt;
    struct node *map[26];
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary *obj=(WordDictionary *)malloc(sizeof(WordDictionary));
    memset(obj, 0, sizeof(WordDictionary));
    return obj;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    while (*word != '\0') {
        if (obj->map[*word - 'a'] == NULL) {
            obj->map[*word - 'a'] = wordDictionaryCreate();
        }
        obj = obj->map[*word - 'a'];
        word++;
    }
    (obj->cnt)++;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    char *p = word;
    if (obj == NULL || word == NULL) {
        return false;
    }
    
    while (*word != '\0') {
        if (*word == '.') {
            for (int i = 0; i < 26; i++) {
                if (obj->map[i] != NULL) {
                    if (wordDictionarySearch(obj->map[i], word + 1) == true) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            if (obj->map[*word - 'a'] == NULL) {
                return false;
            }
            obj = obj->map[*word - 'a'];
        }
        word++;
    }
    return obj->cnt != 0;
}

void wordDictionaryFree(WordDictionary* obj) {
    if (obj == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < 26; i++) {
        if (obj->map[i] != NULL) {
            wordDictionaryFree(obj->map[i]);
        }
    }
    free(obj);
}
/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
```