typedef struct TrieTag {
    bool isEnd;
    int index;
    struct TrieTag *next[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* obj = (Trie* )malloc(sizeof(Trie));
    obj->isEnd = false;
    obj->index = -1;
    memset(obj->next, 0, sizeof(obj->next));

    return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word, int wordIndex) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';

        if (obj->next[index] == NULL) {
            obj->next[index] = trieCreate();
        }
        
        if (i == len - 1) {
            obj->next[index]->isEnd = true;
            obj->next[index]->index = wordIndex;
        }
        obj = obj->next[index];
    }
    
    return;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word, int *wordIndex) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';

        obj = obj->next[index];
        if (obj == NULL) {
            return false;
        }
        //printf("%d %d\n", i, obj->isEnd);
        if (obj->isEnd) {
            *wordIndex = obj->index;
            return true;
        } 
    }

    return false;
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (obj->next[i] != NULL) {
            trieFree(obj->next[i]);
        }
    }
    
    free(obj);
}


#define MAX_WORD_LEN 1001
#define RES_WORD_LEN 1000000
char * replaceWords(char ** dict, int dictSize, char * sentence){
    char word[MAX_WORD_LEN];
    int index;
    int wordIndex;
    Trie* obj = trieCreate();
    int len = strlen(sentence);
    char* res = (char *)malloc(sizeof(char) * RES_WORD_LEN);
    res[0] = '\0'; 

    for (int i = 0; i < dictSize; i++) {
        trieInsert(obj, dict[i], i);
    }

    index = 0;
    
    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || i == len) {
            word[index] = '\0';
            //printf("%s\n", word);
            
            if (trieSearch(obj, word, &wordIndex)) {
                if (wordIndex >= 0 && wordIndex < dictSize) {
                    strcat(res, dict[wordIndex]);
                } else {
                    printf("error!!!");
                }
                
            } else {
                strcat(res, word);
            }

            if (i != len) {
                strcat(res, " ");
            }

            index = 0;
            continue;
        }
       
        word[index++] = sentence[i];
    }

    trieFree(obj);
    return res;
}