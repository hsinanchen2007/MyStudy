### 解题思路
此处撰写解题思路
Trie树，又叫字典树、前缀树（Prefix Tree）、单词查找树 或 键树，是一种多叉树结构。如下图：



上图是一棵Trie树，表示了关键字集合{“a”, “to”, “tea”, “ted”, “ten”, “i”, “in”, “inn”} 。从上图可以归纳出Trie树的基本性质：

根节点不包含字符，除根节点外的每一个子节点都包含一个字符。
从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
每个节点的所有子节点包含的字符互不相同。
通常在实现的时候，会在节点结构中设置一个标志，用来标记该结点处是否构成一个单词（关键字）。

可以看出，Trie树的关键字一般都是字符串，而且Trie树把每个关键字保存在一条路径上，而不是一个结点中。另外，两个有公共前缀的关键字，在Trie树中前缀部分的路径相同，所以Trie树又叫做前缀树（Prefix Tree）。

原文链接：https://blog.csdn.net/lisonglisonglisong/article/details/45584721
### 代码

```c
#define MAX_CHARACTOR_NUM 26

typedef struct tire_node{
    int count; /* 该节点的单次数量 */
    struct tire_node* child[MAX_CHARACTOR_NUM];
} Trie;

/** Initialize your data structure here. */

Trie* allocTrieNode()
{
    Trie* obj = (Trie *)malloc(sizeof(Trie));
    if (obj == NULL) {
        return NULL;
    }
    obj->count = 0;
    for (int i = 0; i <  MAX_CHARACTOR_NUM; i++) {
        obj->child[i] = NULL;
    }
    return obj;
}

Trie* trieCreate() {
    return allocTrieNode();
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    char *p = word;
    Trie *node = obj;
    while (*p) {
        if (node->child[*p - 'a'] == NULL) { /* 对应的节点不存在，则申请一个节点 */
            node->child[*p - 'a'] = allocTrieNode();
        }
        node = node->child[*p - 'a']; /* 指向子节点 */
        p++;
    }
    node->count++;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    char *p = word;

    while (*p && node != NULL) {
        node = node->child[*p - 'a']; /* 循环在树中查找所有节点 */
        p++;
    }

    if (node == NULL) {
        return false; /* 未找到 */
    } else {
        return (node->count > 0 ? (true) : (false)); /* 找到了，但是不是有效单词，只是前缀返回false */
    }
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    char *p = prefix;

    while (*p && node != NULL) {
        node = node->child[*p - 'a'];
        p++;
    }

    return (node == NULL ? (false) : (true));  /* 找到了返回true，未找到返回false，这里和前面查找整个word有点点区别 */
}

void trieFree(Trie* obj) {
    if (obj != NULL) {
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
```