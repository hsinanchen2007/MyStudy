static int cmpstringp(const void *p1, const void *p2) {
    return strlen(* (char * const *) p1) - strlen(* (char * const *) p2);
}

bool inChain(const char* a, const char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    int i = 0, j = 0;
    if (lena == lenb) {
        return false;
    }
    if (lenb - lena > 1) {
        return false;
    }
    while(i< lena && j < lenb) {
        if(a[i] == b[j]) i++;
        j++;
    }
    if (i == lena) return true;
    return false;
}

int longestStrChain(char ** words, int wordsSize) {
    struct hash_entry *tmp = NULL;
    int max = 0, i, len;
    int final_max = 1;
    qsort(words, wordsSize, sizeof(char *), cmpstringp);
    for(int k = 0; k < wordsSize; k++) {
        printf("%s\n", words[k]);
    }
    int *max_len = (int*)malloc(wordsSize*sizeof(int));
    memset(max_len, 0, wordsSize*sizeof(int));

    for (i = 0; i < wordsSize; i++) {
        len = strlen(words[i]);
        int max = 1;
        if (len == 1) {
            max = 1;
        } else {
            int j;
            for (j = 0; j < i; j++) {
              if (inChain(words[j], words[i])) {
                    max = max_len[j] + 1 > max ? max_len[j] + 1 : max;
                }
            }
        }
        max_len[i] = max;
        final_max = final_max > max ? final_max : max;
    }

    return final_max;
}