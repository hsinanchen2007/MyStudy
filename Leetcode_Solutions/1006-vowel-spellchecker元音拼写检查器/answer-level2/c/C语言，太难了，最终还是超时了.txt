```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hashmap {
    char key[8];
    char word[8];
};
int isExist(char *s, char **ss, int sslen)
{
    for (int i = 0; i < sslen; i++) {
        if ((strlen(s) == strlen(ss[i])) && (strncmp(s, ss[i], strlen(s)) == 0)) {
            return i;
        }
    }
    return -1;
}
int isExistMap(char *s, struct hashmap *map, int cnt)
{
    for (int i = 0; i < cnt; i++) {
        if ((strlen(s) == strlen(map[i].key)) && (strncmp(s, map[i].key, strlen(s)) == 0)) {
            return i;
        }
    }
    return -1;
}
void wordtoLowerCase(char *in, char *out) 
{
    int len = strlen(in);
    for (int i = 0; i < len ; i++) {
        if (in[i] >= 'A' && in[i] <= 'Z') {
            out[i] = in[i] + 'a' - 'A';
            continue;
        }
        out[i] = in[i];
    }
}
void devowel(char *in, char *out)
{
    int len = strlen(in);
    for (int i = 0; i < len ; i++) {
        if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u') {
            out[i] = '*';
            continue;
        }
        out[i] = in[i];
    }
}
void solve(char *query, char **ans, int *cnt, 
      char **words_perfect, int words_perfect_cnt, 
      struct hashmap *wordlowmap, int wordlowmap_cnt,
      struct hashmap *wordlowdvmap, int wordlowdvmap_cnt) 
{
    if (isExist(query, words_perfect, words_perfect_cnt) != -1) {
        ans[*cnt] = (char*)calloc(strlen(query) + 1, sizeof(char));
        strncpy(ans[*cnt], query, strlen(query));
        (*cnt)++;
        return;
    }
    char *queryL = (char*)calloc(8, sizeof(char));
    wordtoLowerCase(query, queryL);
    int idx = isExistMap(queryL, wordlowmap, wordlowmap_cnt);
    if (idx != -1) {
        ans[*cnt] = (char*)calloc(strlen(wordlowmap[idx].word) + 1, sizeof(char));
        strncpy(ans[*cnt], wordlowmap[idx].word, strlen(wordlowmap[idx].word));
        (*cnt)++;
        free(queryL);
        return;
    }
    char *queryLV = (char*)calloc(8, sizeof(char));
    devowel(queryL, queryLV);
    idx = isExistMap(queryLV, wordlowdvmap, wordlowdvmap_cnt);
    if (idx != -1) {        
        ans[*cnt] = (char*)calloc(strlen(wordlowdvmap[idx].word) + 1, sizeof(char));
        strncpy(ans[*cnt], wordlowdvmap[idx].word, strlen(wordlowdvmap[idx].word));
        (*cnt)++;
        free(queryL);
        free(queryLV);
        return;
    }
    ans[*cnt] = (char*)calloc(2, sizeof(char));
    strncpy(ans[*cnt],"", 1);
    (*cnt)++;
    free(queryL);
    free(queryLV);
    return;
}
char ** spellchecker(char ** wordlist, int wordlistSize, char ** queries, int queriesSize, int* returnSize){
    char **words_perfect = malloc(5000 * sizeof(char*));
    int words_perfect_cnt = 0;
    struct hashmap *wordlowmap = malloc(5000 * sizeof(struct hashmap));
    for (int i = 0; i < 5000; i++) {
        memset(wordlowmap[i].key, 0, 8);
        memset(wordlowmap[i].word, 0, 8);
    }
    int wordlowmap_cnt = 0;
    char *wordlow = (char*)calloc(8, sizeof(char));
    struct hashmap *wordlowdvmap = malloc(5000 * sizeof(struct hashmap));
    for (int i = 0; i < 5000; i++) {
        memset(wordlowdvmap[i].key, 0, 8);
        memset(wordlowdvmap[i].word, 0, 8);
    }
    int wordlowdvmap_cnt = 0;
    char *wordlowDV = (char*)calloc(8, sizeof(char));
    for (int i = 0; i < wordlistSize; i++) {
        if (isExist(wordlist[i], words_perfect, words_perfect_cnt) == -1) {
            words_perfect[words_perfect_cnt] = (char*)calloc(strlen(wordlist[i]) + 1, sizeof(char));
            strncpy(words_perfect[words_perfect_cnt], wordlist[i], strlen(wordlist[i]));
            words_perfect_cnt++;
        }
        wordtoLowerCase(wordlist[i], wordlow);
        if (isExistMap(wordlow, wordlowmap, wordlowmap_cnt) == -1) {
            strncpy(wordlowmap[wordlowmap_cnt].key, wordlow, strlen(wordlow));
            strncpy(wordlowmap[wordlowmap_cnt].word, wordlist[i], strlen(wordlist[i]));
            wordlowmap_cnt++;
        }
        devowel(wordlow, wordlowDV);
        if (isExistMap(wordlowDV, wordlowdvmap, wordlowdvmap_cnt) == -1) {
            strncpy(wordlowdvmap[wordlowdvmap_cnt].key, wordlowDV, strlen(wordlowDV));
            strncpy(wordlowdvmap[wordlowdvmap_cnt].word, wordlist[i], strlen(wordlist[i]));
            wordlowdvmap_cnt++;
        }
        memset(wordlow, 0, 8);
        memset(wordlowDV, 0, 8);
    }
    char **ans = malloc(queriesSize * sizeof(char*));
    int t = 0;
    for (int i = 0; i < queriesSize; i++) {
        solve(queries[i], ans, &t, words_perfect, words_perfect_cnt, wordlowmap, wordlowmap_cnt, wordlowdvmap, wordlowdvmap_cnt);
    }
    *returnSize = t;
    for (int i = 0; i < words_perfect_cnt; i++) {
        free(words_perfect[i]);
    }
    free(words_perfect);
    free(wordlow);
    free(wordlowDV);
    free(wordlowmap);
    free(wordlowdvmap);
    return ans;
}

```
