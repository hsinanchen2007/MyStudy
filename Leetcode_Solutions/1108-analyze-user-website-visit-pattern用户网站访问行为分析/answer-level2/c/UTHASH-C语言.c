```
写的代码乱七八糟，仅供参考！
看不懂就算了，这题没有想到好思路，吐了！！！

4个HASH
struct HashPath
struct HashPath2ID
struct HashName
struct HashIndex
1、将所有的website，按照字典序排序，生成字符串和INDEX双向 HashPath和HashPath2ID；
2、将输入数据合并为结构体按照时间戳排序；
3、生成HashName，顺序将website加入HashName，
4、遍历HashName，并对应的生成3位索引表加入到HASHindex中；
5、遍历HASHindex，将索引表进行按照访问频率，和数字大小排序（小的即为字典序前面的）；
6、HASHindex第一个元素则为结果；

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSTRLEN 20
#define MAXNUM   100
struct HashPath{
    char keyPath[MAXSTRLEN];
    int  keyIndex;
    UT_hash_handle hh;
};

struct HashPath2ID{
    char keyPath[MAXSTRLEN];
    int  key;
    UT_hash_handle hh;
};

struct HashName{
    char keyName[MAXSTRLEN];
    int  index;
    int  num[MAXNUM];
    UT_hash_handle hh;
};

struct HashIndex{
    char key[MAXSTRLEN];
    int nameIndex;
    char name[MAXNUM][MAXSTRLEN];
    int  index[3];
    int  freQ;
    UT_hash_handle hh;
};

struct HashIndex *g_Index = NULL;
char **g_res = NULL;
struct HashPath *g_path = NULL;
struct HashName *g_head = NULL;
struct HashPath2ID *g_path2ID = NULL;

void insertHashIndex(char *name, int id,int id1, int id2)
{
    struct HashIndex *s = NULL;
    char *key = malloc(MAXSTRLEN);
    memset(key,0,MAXSTRLEN);
    //使用井号防止，数字组合二义性；例如2 21 2和22 1 2
    sprintf(key,"%d#%d#%d",id,id1,id2);
    HASH_FIND_STR(g_Index,key,s);
    if(s == NULL) {
        s = malloc(sizeof(struct HashIndex));
        s->index[0] = id;
        s->index[1] = id1;
        s->index[2] = id2;
        s->freQ = 0;
        s->nameIndex = 0;
        strcpy(s->key,key);
        strcpy(s->name[s->nameIndex],name);
        s->nameIndex++;
        HASH_ADD_STR(g_Index,key,s);
    }
    int flag = 0;
    //同一个用户，相同访问路径不需要重复添加；
    for(int i = 0; i < s->nameIndex; i++) {
        if(strcmp(s->name[i],name) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        s->freQ++;
        strcpy(s->name[s->nameIndex],name);
        s->nameIndex++;
    }
    free(key);
    return;
}

void insertPath2ID(char *keyPath,int key)
{
    struct HashPath2ID *s = NULL;
    HASH_FIND_INT(g_path2ID,&key,s);
    if(s == NULL) {
        s = malloc(sizeof(struct HashPath2ID));
        s->key = key;
        strcpy(s->keyPath,keyPath);
        HASH_ADD_INT(g_path2ID,key,s);
    }
    return;
}

void Index2PathStr(char *keyPath,int key )
{
    struct HashPath2ID *s = NULL;
    HASH_FIND_INT(g_path2ID,&key,s);
    if(s != NULL) {
        strcpy(keyPath,s->keyPath);
    }
    return;
}

int GetIndexByPath(char *keyPath)
{
    struct HashPath *s = NULL;
    HASH_FIND_STR(g_path,keyPath,s);
    if(s != NULL) {
        return s->keyIndex;
    }
    return -1;
}


void insertPath(char *keyPath,int keyIndex)
{
    struct HashPath *s = NULL;
    HASH_FIND_STR(g_path,keyPath,s);
    if(s == NULL) {
        s = malloc(sizeof(struct HashPath));
        s->keyIndex = keyIndex;
        strcpy(s->keyPath,keyPath);
        HASH_ADD_STR(g_path,keyPath,s);
    }
    return;
}

bool isExsit(char *keyPath)
{
    struct HashPath *s = NULL;
    HASH_FIND_STR(g_path,keyPath,s);
    if(s == NULL) {
        return false;
    }
    return true;
}

void insertHashName(char *name, char *path )
{
    struct HashName *s = NULL;
    HASH_FIND_STR(g_head,name,s);
    if(s == NULL) {
        s = malloc(sizeof(struct HashName));
        s->index = 0;
        strcpy(s->keyName,name);
        HASH_ADD_STR(g_head,keyName,s);
    }
    s->num[s->index] = GetIndexByPath(path);
    s->index++;
    return;
}

void ProcessPath2Index()
{
    struct HashName *s = NULL;
    struct HashName *tmp = NULL;
    HASH_ITER(hh,g_head,s,tmp){
        for (int i = 0; i < s->index; i++) {
            for (int j = i + 1; j < s->index; j++) {
                for (int k = j + 1; k < s->index; k++) {
                    insertHashIndex(s->keyName, s->num[i], s->num[j], s->num[k]);
                }
            }
        }
    }
    return;
}
struct allItem{
    char keyName[MAXSTRLEN];
    char path[MAXSTRLEN];
    int  timestamp;
};
int cmp(const void *a, const void *b)
{
    char *aptr = *(char**)a;
    char *bptr = *(char**)b;
    return strcmp(aptr,bptr);
}

int Stcmp(const void *a, const void *b)
{
    struct allItem aptr = *(struct allItem *)a;
    struct allItem bptr = *(struct allItem *)b;
    return aptr.timestamp - bptr.timestamp;
}

int Frecmp(struct HashIndex *a, struct HashIndex *b)
{
    if (b->freQ == a->freQ) {
        for(int i = 0; i < 3; i++) {
            if(a->index[i] != b->index[i]) {
                return a->index[i] - b->index[i];
            }
        }
    }
    return b->freQ - a->freQ;
}

void FreeHashName()
{
    struct HashName *s = NULL;
    struct HashName *tmp = NULL; 
    HASH_ITER(hh,g_head,s,tmp){
        HASH_DEL(g_head,s);
        free(s);
    }
}
void FreeHashPath2ID()
{
    struct HashPath2ID *s = NULL;
    struct HashPath2ID *tmp = NULL; 
    HASH_ITER(hh,g_path2ID,s,tmp){
        HASH_DEL(g_path2ID,s);
        free(s);
    }
}
void FreeHashPath()
{
    struct HashPath *s = NULL;
    struct HashPath *tmp = NULL; 
    HASH_ITER(hh,g_path,s,tmp){
        HASH_DEL(g_path,s);
        free(s);
    }
}
void FreeHashIndex()
{
    struct HashIndex *s = NULL;
    struct HashIndex *tmp = NULL; 
    HASH_ITER(hh,g_Index,s,tmp){
        HASH_DEL(g_Index,s);
        free(s);
    }
}
char ** mostVisitedPattern(char ** username, int usernameSize, int* timestamp, int timestampSize, char ** website, int websiteSize, int* returnSize){
    int keyIndex = 1;
    g_path = NULL;
    g_res = NULL;
    g_Index = NULL;
    g_head = NULL;
    g_path2ID = NULL;
    /*按照字母排序website，后续字符串生成索引，字典序小的索引小，反之则反*/
    char **tempWebsite = malloc(sizeof(char *) * websiteSize);
    for(int i = 0; i < websiteSize; i++) {
        tempWebsite[i] = malloc(MAXSTRLEN);
        memset(tempWebsite[i],0,MAXSTRLEN);
        strcpy(tempWebsite[i],website[i]);
    }
    qsort(tempWebsite,websiteSize,sizeof(char *),cmp);

    for(int i = 0; i < websiteSize; i++) {
        if(isExsit(tempWebsite[i]) == false) {
            insertPath(tempWebsite[i], keyIndex);
            insertPath2ID(tempWebsite[i], keyIndex);
            free(tempWebsite[i]);
            keyIndex++;
        }
    }
    free(tempWebsite);
    /*按照时间戳排序*/
    struct allItem *All = malloc(sizeof(struct allItem) * usernameSize);
    memset(All,0,sizeof(struct allItem) * usernameSize);
    for(int i = 0; i < usernameSize; i++) {
        strcpy(All[i].keyName,username[i]);
        strcpy(All[i].path,website[i]);
        All[i].timestamp = timestamp[i];
    }
    qsort(All,usernameSize,sizeof(struct allItem),Stcmp);
    /*排序后插入HASH*/
    for(int i = 0; i < usernameSize; i++) {
        insertHashName(All[i].keyName, All[i].path);
    }
    free(All);

    /*暴力法遍历每个用户的访问行为，生成索引，例如home,aboout carre，生成3#1#2*/
    ProcessPath2Index();

    struct HashIndex *s = NULL;
    struct HashIndex *tmp = NULL; 
    g_res = malloc(sizeof(char *) * 3);
    for(int i = 0; i < 3; i++) {
        g_res[i] = malloc(MAXSTRLEN);
        memset(g_res[i],0,MAXSTRLEN);
    }
    HASH_SORT(g_Index,Frecmp);
    HASH_ITER(hh,g_Index,s,tmp){ 
        Index2PathStr(g_res[0], s->index[0]);
        Index2PathStr(g_res[1], s->index[1]);
        Index2PathStr(g_res[2], s->index[2]);
        break;
    }
    FreeHashName();
    FreeHashPath();
    FreeHashIndex();
    FreeHashPath2ID();
    *returnSize = 3;
    return g_res;
}
```
