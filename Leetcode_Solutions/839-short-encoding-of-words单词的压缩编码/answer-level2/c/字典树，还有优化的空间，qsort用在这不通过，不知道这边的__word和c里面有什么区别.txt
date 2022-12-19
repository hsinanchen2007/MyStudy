### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX 26
#define GET_INDEX(c) (c) - 'a'

struct node {
    struct node *next[MAX];
};

struct node * trieNew()
{
    struct node * tmp = (struct node *)malloc(sizeof(struct node));
    memset(tmp, 0, sizeof(struct node));
    return tmp;
}

void trie_add(struct node *node, char *s)
{
    int len = strlen(s);
    while(--len >= 0){
        if (node->next[GET_INDEX(s[len])] == NULL) {
            node->next[GET_INDEX(s[len])] = trieNew();
        }
        node = node->next[GET_INDEX(s[len])];
    }
    return;
}

bool trie_check(struct node *node, char *s)
{
    int len = strlen(s);
    while(--len >= 0) {
        if (node->next[GET_INDEX(s[len])] == NULL) {
            return false;
        }
        node = node->next[GET_INDEX(s[len])];
    }

    return true;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    int len = 0;
    struct node *head = trieNew();
    char *tmp = NULL;

    if(wordsSize == 0){
        return 0;
    }
    if(wordsSize == 1){
        return strlen(words[0]) + 1;
    }

    //长度排序
    for(int i = 0; i<wordsSize;i++){
        for(int j=i; j<wordsSize; j++) {
            if(strlen(words[i]) <= strlen(words[j])){
                tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
            }
        }
    }
    
    for (int i = 0; i < wordsSize; i++) {
  //      printf(" %s", words[i]);
        if(trie_check(head, words[i]) != true) {
            trie_add(head, words[i]);
            len += strlen(words[i]) + 1;
        }
    }
  //  printf("\r\n");

    return len;
}
```