```
#define APL_NUM 26
typedef struct _TireTree TireTree;
struct _TireTree{
   TireTree *child[APL_NUM]; 
};
TireTree * CreateOne() {
    TireTree *root = (TireTree*) malloc(sizeof(TireTree));
    memset(root, 0, sizeof(TireTree));
    return root;
}
int Compare(const void *a, const void *b) {
    char** ca = (char**)a;
    char** cb = (char**)b;
    return strlen(*cb) > strlen(*ca);
}
int InsertTireTree(TireTree *tree, char *s) {
    int end = strlen(s) - 1;
    int flag = 1;
    for(int i = end; i >= 0; i--) {
        if (tree->child[s[i] - 'a'] == NULL) {
            printf("%s %c\n", s, s[i]);
            TireTree *child = CreateOne();
            tree->child[s[i] - 'a'] = child;
            flag = 0;
        }
        tree = tree->child[s[i] - 'a'];
    }
    return flag;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (wordsSize == 0) {
        return 0;
    }
    if (wordsSize == 1) {
        return strlen(words[0]) + 1;
    }
    qsort(words, wordsSize, sizeof(char*), Compare);
    TireTree *root = CreateOne();
    int count = 0;
    for(int i = 0; i < wordsSize; i++) {
        if (InsertTireTree(root, words[i]) == 0) {
            count += strlen(words[i]) + 1;
        }
    }
    return count;
}
```
