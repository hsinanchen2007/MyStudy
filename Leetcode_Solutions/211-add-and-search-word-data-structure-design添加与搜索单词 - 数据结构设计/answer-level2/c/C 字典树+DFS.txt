效率不高，仅供参考。
```
typedef struct node {
    char val;
    struct node *next[26]; /* 26叉树 */
    int  end;
} WordDictionary;
WordDictionary* wordDictionaryCreate() {
    int i;
    WordDictionary *res = calloc(1, sizeof(WordDictionary));
    for (i = 0; i < 26; i++) {
        res->next[i] = NULL;
    }
    return res;
}
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    int i, h;
    WordDictionary *curr = obj;
    if (word == NULL) {
        return;
    }
    for (i = 0; i < strlen(word); i++) {
        h = word[i] - 'a';
        if (curr->next[h] == NULL) {
            curr->next[h] = wordDictionaryCreate();
            curr->next[h]->val = word[i];
        }
        curr = curr->next[h];
    }
    curr->end = 1;
    return;
}
/* 最后的字符'.'需要特殊处理 */
bool SearchPoint(WordDictionary *curr)
{
    int i;
    for (i = 0; i < 26; i++) {
        if ((curr->next[i] != NULL) && (curr->next[i]->end == 1)) {
            return true;
        }
    }  
    return false;
}
bool Check(WordDictionary* obj, char * word)
{
    if (word == NULL) {
        return false;
    }
    if (*word == '\0') { /* 递归出口，后封装的 */
        return false;
    }
    if (obj == NULL) { /* 递归出口，后封装的 */
        return false;
    } 
    return true;
}
/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
    int i, j, h;
    bool res = false;
    WordDictionary *curr = obj;
    if (Check(obj, word) == false) {
        return false;
    }
    for (i = 0; i < strlen(word); i++) {
        if (word[i] != '.') {
            h = word[i] - 'a';
            if (curr->next[h] == NULL) {
                return false;
            }
            curr = curr->next[h];
        } else {
            if (i < strlen(word) - 1) {
                for (j = 0; j < 26; j++) {
                    /* 26叉树递归，如果当前是.且后面还有字符，则直接搜后面的子串 */
                    res |= wordDictionarySearch(curr->next[j], &word[i + 1]);
                    if (res != false) {
                        return true;
                    }
                }
                return false; /* 只要开始递归就以递归总结果为准 */
            }
            if (SearchPoint(curr) == true) { /* 最后末尾的一个通配符.的处理 */
                return true;
            }  
            curr = NULL;
        }  
    }
    if ((curr != NULL) && (curr->end == 1)) {
        return true;
    }
    return false;
}
void wordDictionaryFree(WordDictionary* obj) {
    int i;
    for (i = 0; i < 26; i++) {
        if (obj->next[i] != NULL) {
            wordDictionaryFree(obj->next[i]);
        }
    }
    free(obj);
}

```

![未命名.bmp](https://pic.leetcode-cn.com/f630879bee214f0f95dae36c43f9a993bcaf52c4ace85f49d892bda59f77243f-%E6%9C%AA%E5%91%BD%E5%90%8D.bmp)

