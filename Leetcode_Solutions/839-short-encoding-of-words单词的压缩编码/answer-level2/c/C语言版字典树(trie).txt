### 解题思路
字典树(trie)，也不知道是否有内存泄露，统计总长度的时候用的是深度搜索，但是总感觉用广度搜索更好，因为字符串的长度可以看做是节点的深度。以上说的两点没有细究，如果写的有的有问题还请看官给予指点
### 代码

```c
#define MAX_CHAR_NUM 26 /* 26个字母 */
static int totalLen;

typedef struct tag_TrieNode {
    /* 表示指向26个字母 */
    struct tag_TrieNode *pNext[MAX_CHAR_NUM];
} trieNode;

/* 反转单词，使后缀变为前缀 */
void reverseWord(char *word)
{
    if (word == NULL) {
        return;
    }

    int start = 0;
    int end = strlen(word) - 1;
    char tempChar;

    while (start < end) {
        tempChar = word[start];
        word[start] = word[end];
        word[end] = tempChar;

        start++;
        end--;
    }

    return;
}

/* 如果word在树中不存在，那就其插入树
   调用者需要自己保证属于同一株树 */
void insertTrie(trieNode **pTree, char *word)
{
    if (pTree == NULL || word == NULL) {
        return;
    }

    trieNode *tempNode = NULL;
    if (*pTree == NULL) {
        tempNode = (trieNode *)malloc(sizeof(trieNode));
        if (tempNode == NULL) {
            return;
        }
        (void)memset(tempNode, 0, sizeof(trieNode));
        *pTree = tempNode;
    }

    trieNode *tree = *pTree;
    int index = 1;
    int wordLen = strlen(word);
    
    while (index < wordLen) {
        /* 说明字典中还没有这种组合 */
        if (tree->pNext[word[index] - 'a'] == NULL) {
            tempNode = (trieNode *)malloc(sizeof(trieNode));
            if (tempNode == NULL) {
                return;
            }
            (void)memset(tempNode, 0, sizeof(trieNode));
            tree->pNext[word[index] - 'a'] = tempNode;
        } 

        tree = tree->pNext[word[index] - 'a'];
        index++;
    }

    return;
}

/* 遍历树，获得所有字符串的总长度,count可以看做是这个节点的深度 */
void traversalTree(trieNode *tree, int count)
{
    if (tree == NULL) {
        totalLen += count + 1;
        return;
    }

    int loop = 0;
    bool isLeaf = true;
    for (; loop < MAX_CHAR_NUM; loop++) {
        if (tree->pNext[loop] == NULL) {
            continue;
        }

        /* 只要有一个指针不为NULL，说明就不是叶子节点 */
        isLeaf = false;

        /* 加自己这个字母的长度(1) */
        traversalTree(tree->pNext[loop], count + 1);
    }

    /* 如果自己就是叶子节点，说明字符串到头了，需要在totalLen加上该字符串的长度(深度)和# */
    if (isLeaf == true) {
        totalLen += count + 1 + 1;
    }

    return;
}

/* 遍历释放树上涉及到的所有内存 */
void freeTrieTree(trieNode *tree)
{
    if (tree == NULL) {
        return;
    }

    trieNode *tempNode;
    int loop;

    for (loop = 0; loop < MAX_CHAR_NUM; loop++) {
        freeTrieTree(tree->pNext[loop]);
        tree->pNext[loop] = NULL;
    }

    free(tree);
    return;
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize <= 0) {
        return 0;
    }

    int loop;
    int tempLen = 0;
    trieNode *wordList[MAX_CHAR_NUM] = {0};
    
    totalLen = 0;
    for (loop = 0; loop < wordsSize; loop++) {
        /* 将所有字符串反转 */
        reverseWord(words[loop]);
        insertTrie(&(wordList[words[loop][0] - 'a']), words[loop]);
    }

    for (loop = 0; loop < MAX_CHAR_NUM; loop++) {
        if (wordList[loop] == NULL) {
            continue;
        }
        
        traversalTree(wordList[loop], tempLen);

        /* 每遍历完一棵树就将其内存释放 */
        freeTrieTree(wordList[loop]);
    }

    return totalLen;
}
```