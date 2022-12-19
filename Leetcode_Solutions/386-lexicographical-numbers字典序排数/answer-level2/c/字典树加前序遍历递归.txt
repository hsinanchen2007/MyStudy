#define MAX 10    //字符集大小
typedef struct TrieNode
{
    int nCount;//记录该字符出现次数    
    struct TrieNode* next[MAX];
} TrieNode;
 
TrieNode Memory[5000000];
int allocp = 0;
 
/*初始化*/
void InitTrieRoot(TrieNode* *pRoot)
{
    *pRoot = NULL;
}
 
/*创建新结点*/
TrieNode* CreateTrieNode()
{
    int i;
    TrieNode *p;
    p = &Memory[allocp++];
    p->nCount = 1;    
    for(i = 1; i <= MAX; i++)
    {
        p->next[i] = NULL;
    }
    return p;
}
 
/*插入*/
void InsertTrie(TrieNode* *pRoot,char *s)
{
    int i, k;
    TrieNode* p;
    
    if(!(p = *pRoot))
    {
        p = *pRoot = CreateTrieNode();
    }
    
    i = 0;
    
    while(s[i])
    {        
        k = s[i++] - '0';//确定branch
        if (p->next[k] == NULL) {
            p->next[k] = CreateTrieNode();
        } else {
            p->next[k]->nCount++;            
        }
        p = p->next[k]; 
    } 
    
}
 
//查找
int SearchTrie(TrieNode* *pRoot,char *s)
{
    TrieNode *p;
    int i,k;
    if(!(p = *pRoot))
    {
        return 0;
    }
    i = 0;
    while(s[i])
    {
        k = s[i++] - '0';
        if(p->next[k] == NULL) {
            return 0;
        }
        p = p->next[k];
    }

    return p->nCount;
}

int g_total = 0;

void preOrder(TrieNode* p, char* word, int pos, int* ret) {
    if(!p)
    {
        return;
    }
   
    // 访问剩余节点
    for (int i = 0; i < MAX; i++) {
        if (p->next[i] != NULL) {
            sprintf(word + pos, "%d", i);
            // printf("word = %s\n", word);
            ret[g_total++] = atoi(word);
            
            preOrder(p->next[i], word, pos + 1, ret);
            word[pos] = '\0';
        }
    }
    return;
}

#define N 5000002
int* lexicalOrder(int n, int* returnSize){
    if (n == 0) {
        *returnSize = 0;
        return NULL;    
    }
    TrieNode* pRoot = (TrieNode*)CreateTrieNode();
    g_total = 0;
    int* ret = (int*) calloc(N, sizeof(int));
    

    for (int i = 1; i <= n; i++) {
        char str[10] = {0};
        sprintf(str, "%d", i);  
        // printf("str = %s\n", str);
        InsertTrie(&pRoot, str);  
    }
    char word[10] = {0};
    preOrder(pRoot, word, 0, ret);

    *returnSize = g_total;
    return ret;
}