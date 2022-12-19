```
#define ALPHABET_SIZE 26

typedef struct Trie {
    bool hasVisited;
    bool hasChildren;
    struct Trie* children[ALPHABET_SIZE];
}Trie;

// 创建一个子树
Trie* createTrie()
{
    Trie* res = (Trie*)malloc(sizeof(Trie));
    res->hasVisited = false;
    res->hasChildren = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        res->children[i] = NULL;
    }

    return res;
}

// 每个单词插入到 树里面，必要时申请新的子树
void insertWord(Trie* trie, char* word)
{
    int length = strlen(word);
    char oneChar;

    for (int i = length - 1; i >= 0; i--) {
        oneChar = word[i];
        if (trie->children[oneChar - 'a'] == NULL) {
            trie->children[oneChar - 'a'] = createTrie();
            trie->hasChildren = true;
        }
        // 指针指向子树，准备创建下一个有效字符
        trie = trie->children[oneChar - 'a'];
    }
}

// 依次释放每个子树
void freeTrie(Trie* trie)
{
    if (trie == NULL) {
        return;
    }
    Trie* ptr = trie;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (ptr->children[i] && (ptr->hasChildren)) {
            // 递归遍历每个子树
            freeTrie(ptr->children[i]);
        } else if (ptr->children[i]) {
            free(ptr->children[i]);
            ptr->children[i] = NULL;
        }
    }
}

// DFS遍历，记录结果
//      e | l 
//     m  |   l
//    i   |    e
//   t    |     b
// DFS有多少个有效分支，就需要多少个单词，也就是说需要最小的字符长度
int g_counts;
void dfs(Trie* trie, int level)
{
    if (trie == NULL) {
        return;
    }
    
    Trie* ptr = trie;

    // visit.
    if (!trie->hasChildren) {
        g_counts += (level + 1);
        return;
    }

    // loop all children.
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (trie->children[i] != NULL) {
            dfs(trie->children[i], level + 1);
        }
    }
}

int minimumLengthEncoding(char ** words, int wordsSize){
    if ((words == NULL) || (wordsSize <= 0)) {
        return 0;
    }

    Trie* trie = createTrie();

    // create Trie
    for (int i = 0; i < wordsSize; i++) {
        insertWord(trie, words[i]);
    }

    // count words.
    g_counts = 0;
    dfs(trie, 0);
    freeTrie(trie);
    return g_counts;
}
```
