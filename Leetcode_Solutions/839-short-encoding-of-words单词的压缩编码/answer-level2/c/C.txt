### 解题思路
自己琢磨了半天的字典树，那必须得贴上来。。见笑见笑

### 代码

```c
#define MAXSIZE 26 //字符集大小

typedef struct DictNode{
    char val;
    bool visit; //搜索过该叶子节点则设为ture
    int numChildren;
    struct DictNode** children;
}DictNode;

//字典树
DictNode* CreateDictNode(char c);
void InsertDict(DictNode* Dict, char* s);
int SearchDict(DictNode* Dict, char* s);
char* ReverseStr(char* s);

int minimumLengthEncoding(char ** words, int wordsSize){
    DictNode* Dict = CreateDictNode(35);
    int i, count = 0;

    for(i=0; i<wordsSize; i++)
        InsertDict(Dict, ReverseStr(words[i]));

    for(i=0; i<wordsSize; i++)
        count += SearchDict(Dict, ReverseStr(words[i]));
    
    return count;
}

//生成字典树节点
DictNode* CreateDictNode(char c){
    DictNode* node = malloc(sizeof(DictNode));
    node->val = c;
    node->visit = false;
    node->numChildren = 0;
    node->children = malloc(sizeof(DictNode *) * MAXSIZE);
    return node;
}

//字典树插入单词
void InsertDict(DictNode* Dict, char* s){
    DictNode* root = Dict;
    int i = 0, j, len = strlen(s);
    bool flag = true;

    for(i=0; i<len; i++){
        if(root->numChildren == 0)
            break;
        
        for(j=0; j<root->numChildren; j++){
            if(s[i] == root->children[j]->val){
                root = root->children[j];
                break;
            }

            if(j == root->numChildren - 1)
                flag = false;
        }

        if(!flag)
            break;
    }
    
    while(i < len){
        root->children[root->numChildren] = CreateDictNode(s[i++]);
        root = root->children[root->numChildren++];
    }
}

//搜索单词末尾是否为叶子节点，是则返回长度，否则返回0
int SearchDict(DictNode* Dict, char* s){
    DictNode* root = Dict;
    int i, j, len = strlen(s);

    for(i=0; i<len; i++){
        for(j=0; j<root->numChildren; j++){
            if(s[i] == root->children[j]->val){
                root = root->children[j];
                break;
            }
        }

        if(root->numChildren == 0)
            if(!root->visit){
                root->visit = true;
                return len+1;
            }else
                return 0;
    }

    return 0;
}

//反转字符串
char* ReverseStr(char* s){
    int i, len = strlen(s);
    char* rs = malloc(sizeof(char) * (len+1));

    for(i=0; i<len; i++)
        rs[i] = s[len-1-i];
    
    rs[len] = '\0'; //勿忘我
    return rs;
}

```