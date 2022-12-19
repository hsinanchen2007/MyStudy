字典树，通常又名前缀数（Trie，百度上的符号定义），典型的应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常用于搜索引擎系统用于文本词频统计
优点：最大限度地减少无畏的字符串比较

前缀数的3个基本性质：
1.	根节点不包含字符，除根节点外的每一个节点都只包含一个字符（character）
2.	从根节点到某一节点，路径上经过的字符链接起来，为该节点对应的字符串
3.	每个节点的所有子节点包含的字符都不相同

C语言实现重点在于malloc and free; malloc时需要初始化，free可以使用递归（DFS的C语言实现方案，递归代码实现）。

该题目利用字典树，反序Push字典树（该题目是要求单词从后往前存在相同就可以压缩），然后再考虑Push是一个新的字典，就在外面增加总长度，所以一次遍历可计算总长度。

本人尝试暴力比较解法，时间1s左右，优化后能够在500ms左右。尝试字典树后80ms左右。
#define WORD_MAX 26
#define NULL     0
#define REPEAT   -1

typedef struct {
    char thisStr;
    struct TrieTree *nextStr[WORD_MAX];
}TrieTree;

TrieTree g_rootNode;

void CleaTrieNode(TrieTree *curNode)
{
    if (curNode == NULL) {
        return;
    }
    for (int i = 0; i < WORD_MAX; i++) {
        if (curNode->nextStr[i] != NULL) {
            CleaTrieNode(curNode->nextStr[i]);
        }
    }
    
    free(curNode);
}

void CleanAllTrieNode()
{
    TrieTree curNode = g_rootNode;
    for (int i = 0; i < WORD_MAX; i++) {
        CleaTrieNode(curNode.nextStr[i]);
    }
}

void InitRootNode(TrieTree *thisNode)
{
    thisNode->thisStr = '\0';
    for (int i = 0; i < WORD_MAX; i++) {
        thisNode->nextStr[i] = NULL;
    }
} 

int PushTrieNode(char *curWords, int wordsLen)
{
    TrieTree *curNode = &g_rootNode;
    bool haveNew = false;

    for (int i = wordsLen - 1; i >= 0; i--) {    
        TrieTree *thisNode = curNode;
        int index          = curWords[i] - 'a';
        if (thisNode->nextStr[index] == NULL) {

            thisNode->nextStr[index] = malloc(sizeof(TrieTree));
            if (thisNode->nextStr[index] == NULL) {
                return;
            }
            InitRootNode(thisNode->nextStr[index]);
            TrieTree *nextNode = thisNode->nextStr[index];
            nextNode->thisStr = curWords[i];
            haveNew = true;
        }
        curNode = thisNode->nextStr[index];
        if (curNode == NULL) {
            break;
        }
    }
    return haveNew == true ? 0 : REPEAT;
}

int CompareWords(const void *left, const void *right)
{
    return strcmp((char *)(*(char **)left), (char *)(*(char **)right));
}

int minimumLengthEncoding(char words[3][7], int wordsSize) {
    InitRootNode(&g_rootNode);

    qsort(words, wordsSize, sizeof(words[0]), CompareWords);
    
    int allWordLen = 0;
    for (int i = 0; i < wordsSize; i++) {
        int wordsLen = strlen(words[i]);
        if (PushTrieNode(words[i], wordsLen) == 0) {
            allWordLen += (wordsLen + 1);
        }
    }
    CleanAllTrieNode();
    return allWordLen;
}
