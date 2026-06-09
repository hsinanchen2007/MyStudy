```

typedef struct node{
    char word[31];
    UT_hash_handle hh;
} HASHSET;

int comp(char** a, char** b) {
    int len =  strlen(*b) - strlen(*a);
    if(len!=0) return len;
    else{
        int len1 = strlen(*a);
        for(int i=0; i<len1; i++){
            if((*a)[i] != (*b)[i]){
                return (*a)[i] - (*b)[i];
            }
        }
    }
    return *a - *b;
}

char * longestWord(char ** words, int wordsSize){
    HASHSET *hash = NULL;
    for(int i=0; i<wordsSize; i++) {
        HASHSET* tmp = (HASHSET*)malloc(sizeof(HASHSET));
        int len = strlen(words[i]);
        memset(tmp->word, 0, len+1);
        memcpy(tmp->word, words[i], len);
        HASH_ADD_STR(hash, word, tmp);
    }
    qsort(words, wordsSize, sizeof(char*), comp);

    for(int i=0; i<wordsSize; i++) {

        int len = strlen(words[i]);
        int count = 0;
        HASHSET* isFind = NULL;
        for(int j=1; j<len; j++){
            char tmp[31] = {0};
            memcpy(tmp, words[i], j);
            
            HASH_FIND_STR(hash, tmp, isFind);
            if(isFind){
                count++;
            }else{
                break;
            }
        }

        if(count==len-1){
            return words[i];
        }
    }
    return NULL;
}

```
