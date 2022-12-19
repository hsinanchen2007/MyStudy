### 解题思路
字典树不难，就是复杂的寻找总是让我这个菜鸟捉急。

这里我是先排序，然后在单词存入字典树的时候就马上判断它是否为逐步添加的单词，并且要立刻保存其长度进行比较。

### 代码

```c
#define MAX 26 //字符集大小

typedef struct TrieNode
{
    int nCount; //记录该字符出现次数
    bool single;
    struct TrieNode* next[MAX];
}TrieNode;
 
TrieNode* CreateTrieNode();
int char_cmp(const void* str1, const void* str2);
void InsertTrie(TrieNode* root, char* s);
int SearchTrie(TrieNode* root, char* s);

char * longestWord(char ** words, int wordsSize){
    TrieNode* root = CreateTrieNode();
    int i, j, len, maxlen = -1;

    //字符串排序
    qsort(words, wordsSize, sizeof(char *), char_cmp);

    //创建字典树
    for(i=0; i<wordsSize; i++){
        InsertTrie(root, words[i]);
        
        len =  SearchTrie(root, words[i]);

        if(len > maxlen){
            maxlen = len;
            j = i;
        }

        if(len == maxlen)
            j = (strcmp(words[i], words[j]) > 0) ? j : i;
    }

    return words[j];
}
 
//创建新结点
TrieNode* CreateTrieNode()
{
    TrieNode* root = malloc(sizeof(TrieNode));
    int i;
    root->nCount = 0;
    root->single = false;
    for(i=0; i<MAX; i++)
        root->next[i] = NULL;
    return root;
}

//字符串比较函数
int char_cmp(const void* str1, const void* str2){
    char* s1 = *(char **)str1;
    char* s2 = *(char **)str2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2)
        return len1 - len2;
    else
        return strcmp(s1, s2);
}

//存入单词
void InsertTrie(TrieNode* root, char* s){   
    if(strlen(s) > 0)
        root->nCount++;
    
    int i = 0, k, len = strlen(s);
    TrieNode* p = root;

    while(s[i]){
        k = s[i++] - 'a';

        if(!p->next[k])
            p->next[k] = CreateTrieNode();
        
        if(p->next[k]->nCount < len-i)
            p->next[k]->single = true;

        p->next[k]->nCount++;
        p = p->next[k];
    }
}
 
//查找，返回单词长度。若单词不满足逐步添加条件，返回-2;
int SearchTrie(TrieNode* root, char* s){
    if(!root)
        return 0;
    
    TrieNode* p = root;
    int i = 0, k, len = strlen(s);

    while(s[i]){
        k = s[i++] - 'a';

        if(!p->next[k])
            return -2;

        if(p->next[k]->single)
            return -2;
        
        p = p->next[k];
    }

    return len;
}

```