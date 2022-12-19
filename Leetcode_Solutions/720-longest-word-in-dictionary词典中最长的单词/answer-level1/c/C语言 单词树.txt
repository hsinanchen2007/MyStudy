### 解题思路
一把过，使用单词数，用了几个递归解决
![image.png](https://pic.leetcode-cn.com/6c59aef28f2dbe72c6bf2949a492575024ac6d4e7bb4b6e08b6950868e9b252c-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_MAX_LEN 31
#define MY_NUM_SIZE 26
struct MyNode {
    int isEnd;
    int isRoot;
    char ch;
    struct MyNode *subNode;
};
struct MyStatus {
    struct MyNode root;
};
struct MyRlt {
    char *cur;
    char curlen;
    char *rlt;
    char rltlen;
};
void nodeFree(struct MyNode *n)
{
    int i;
    if (n->subNode == NULL) {
        return;
    }
    for (i = 0; i < MY_NUM_SIZE; i++) {
        nodeFree(&n->subNode[i]);
    }
    free(n->subNode);
    n->subNode = NULL;
}
void sFree(struct MyStatus *s)
{
    nodeFree(&s->root);
    return;
}
void sInit(struct MyStatus *s)
{
    s->root.isRoot = 1;
    s->root.isEnd = 1;
    s->root.subNode = NULL;
}
void rFree(struct MyRlt *r)
{
    if (r->cur != NULL) {
        free(r->cur);
        r->cur = NULL;
    }
}
int rInit(struct MyRlt *r)
{
    r->cur = (char*)calloc(MY_MAX_LEN, sizeof(char));
    if (r->cur == NULL) {
        return MY_FAIL;
    }
    r->rlt = (char*)calloc(MY_MAX_LEN, sizeof(char));
    if (r->rlt == NULL) {
        free(r->cur);
        return MY_FAIL;
    }
    r->curlen = 0;
    r->rltlen = 0;
    return MY_OK;
}
/* 构建语法树 */
void process(struct MyNode *n, char *str, int len)
{
    int i;
    if (len == 0) {
        n->isEnd = 1;
        return;
    }
    if (n->subNode == NULL) {
        n->subNode = (struct MyNode*)calloc(MY_NUM_SIZE, sizeof(struct MyNode));
        if (n->subNode == NULL) {
            printf("calloc fail ...\n");
            return;
        }
        for (i = 0; i < MY_NUM_SIZE; i++) {
            n->subNode[i].ch = i + 'a';
        }
    }
    process(&(n->subNode[*str - 'a']), str + 1, len - 1);
}
/* 查找语法树 */
void find(struct MyRlt *r, struct MyNode *n)
{
    int i, lcur;
    lcur = r->curlen;
    if (n->isEnd != 1) {
        return;
    }
    if (n->isRoot != 1) {
        r->cur[r->curlen] = n->ch;
        r->curlen++;
        if (r->curlen > r->rltlen) {
            memcpy(r->rlt, r->cur, r->curlen);
            r->rltlen = r->curlen;
        }
    }
    if (n->subNode == NULL) {
        r->curlen = lcur;
        return;
    }
    for (i = 0; i < MY_NUM_SIZE; i++) {
        find(r, &n->subNode[i]);
    }
    r->curlen = lcur;
    return;
}
char * longestWord(char ** words, int wordsSize){
    int i, ret;
    struct MyStatus s;
    struct MyRlt r;
    sInit(&s);
    ret = rInit(&r);
    if (ret != MY_OK) {
        sFree(&s);
        return "";
    }
    /* 构建语法树 */
    for (i = 0; i < wordsSize; i++) {
        process(&s.root, words[i], strlen(words[i]));
    }
    /* 查找语法树 */
    find(&r, &s.root);
    sFree(&s);
    rFree(&r);
    return r.rlt;
}
```