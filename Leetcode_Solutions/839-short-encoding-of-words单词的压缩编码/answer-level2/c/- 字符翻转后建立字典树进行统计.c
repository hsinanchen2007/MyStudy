- 字符翻转后建立字典树进行统计


```
typedef struct WordNode {
    int count;
    struct WordNode *next[26];
}MyWordNode;

MyWordNode * createMyWordNode() {
    MyWordNode * node = (MyWordNode *)malloc(sizeof(MyWordNode));
    memset(node, 0, sizeof(MyWordNode));
    node->count = 0;
    return node;
}
void insertWordDict(MyWordNode *root, char* c) {
    MyWordNode * curr = root;
    int len = strlen(c);
    int j;
    for (j = len - 1; j >= 0; j--) {
        if (curr->next[c[j] - 'a'] == NULL) {
            MyWordNode *node = createMyWordNode();
            curr->next[c[j] - 'a'] = node;
        }
        curr = curr->next[c[j] - 'a'];
    }
    curr->count = len + 1;
}
void countWordDict(MyWordNode *root, int *count) {
    bool isLeaf = true;
    for (int i = 0; i < 26; i++) {
        if (root->next[i] != NULL) {
            isLeaf = false;
            countWordDict(root->next[i], count);
        }
    }
    if (isLeaf) {
        *count = *count + root->count;
    }
    return;
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize <= 0) {
        return 0;
    }
    MyWordNode *root = createMyWordNode();
    for (int i = 0; i < wordsSize; i++) {
        insertWordDict(root, words[i]);
    }
    int count = 0;
    countWordDict(root, &count);
    return count;
}
```

