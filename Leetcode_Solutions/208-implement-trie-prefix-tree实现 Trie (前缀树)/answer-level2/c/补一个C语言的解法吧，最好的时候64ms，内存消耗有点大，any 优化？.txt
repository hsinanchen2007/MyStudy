typedef struct ttt{
    struct ttt* next[26];
    int endFlag;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* ret;

    ret = (Trie *)malloc(sizeof(Trie));
    ret->endFlag = 0;
    for (int i = 0; i < 26; i++) {
        ret->next[i] = NULL;
    }
    return ret;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie* temp;
    int len = strlen(word);
    int k = 0;

    if (len < 1) {
        return;
    }

    while (k < len) {
        if (obj->next[word[k] - 'a'] == NULL) {
            temp = (Trie *)malloc(sizeof(Trie));
            temp->endFlag = 0;
            for (int i = 0; i < 26; i++) {
                temp->next[i] = NULL;
            }
            obj->next[word[k] - 'a'] = temp;
        }        
        obj = obj->next[word[k] - 'a'];
        k++;
    }
    obj->endFlag = 1;  
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    while (*word != '\0' && obj->next[*word - 'a'] != NULL) {        
        obj = obj->next[*word - 'a'];
        word++;
    }
    return (*word == '\0' && obj->endFlag == 1);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    while (*prefix != '\0' && obj->next[*prefix - 'a'] != NULL) {        
        obj = obj->next[*prefix - 'a'];
        prefix++;
    }
    return *prefix == '\0';
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        trieFree(obj->next[i]);
        if (obj->next[i] != NULL) {
            free(obj->next[i]);
        }
    }   
}