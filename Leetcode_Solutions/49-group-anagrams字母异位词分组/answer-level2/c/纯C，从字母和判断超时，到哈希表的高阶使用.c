### 解题思路
方法一：
.   通过26个字母的加法判定连个字符串是否是字母异位词组合，
.   方法可以行，但是超时，并且没有优化的空间


方法二：学习哈希表的高阶使用方法
.   1,使用质数解决哈希表关键字的问题，26个字母对应26个质数，不同字母组合的乘积肯定不同
.   2,创建一个大小为 hashSize 的二维指针作为数组，
.   3,使用所有字符串的 key % hashSize 分配到数组不同的位置对应的链表中
.   4,每个二维数组中元素是一个链表，链表的元素是 字符串 key, 字符串位置 pos, 下一个指针 pNext 组成
.   5,将每个链表中的元素按照 key 分配，字母异位词组合 具有相同的 key 肯定在同一个链表中

学习点
.   1,质数的运用，
.   2,哈希表加二维链表的运用，数据结构的定义，哈希表初始化，元素插入，最后空间释放
.   3，double类型的使用，浮点型求余系统函数 fmod,  float 类型数据求余 fmodf

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//方法二：学习哈希表的高阶使用方法
//1,使用质数解决哈希表关键字的问题，26个字母对应26个质数，不同字母组合的乘积肯定不同
//2,创建一个大小为 hashSize 的二维指针作为数组，
//3,使用所有字符串的 key % hashSize 分配到数组不同的位置对应的链表中
//4,每个二维数组中元素是一个链表，链表的元素是 字符串 key, 字符串位置 pos, 下一个指针 pNext 组成
//5,将每个链表中的元素按照 key 分配，字母异位词组合 具有相同的 key 肯定在同一个链表中

//学习点
//1,质数的运用，
//2,哈希表加二维链表的运用，数据结构的定义，哈希表初始化，元素插入，最后空间释放
//3，double类型的使用，浮点型求余系统函数 fmod,  float 类型数据求余 fmodf

#define     HASH_SIZE       199
#define     MAX_COL_SIZE    200         //相同 字母异位词的最大个数

//二维哈希链表元素定义
struct Hash_Node {
    double              key;
    int                 value;
    struct Hash_Node*   pNext;
};

//哈希表定义
struct Hash_Table {
    struct Hash_Node**  pHashHead;
    int                 iHashSize;
};

//函数一：哈希表初始化
bool hashTableInit(struct Hash_Table** pHashTable) {
    bool    bRet    = true;
    int     i       = 0;

    *pHashTable = (struct Hash_Table*)malloc(sizeof(struct Hash_Table));
    if (NULL == *pHashTable) return false;

    (*pHashTable)->iHashSize = HASH_SIZE;
    (*pHashTable)->pHashHead = (struct Hash_Node**)malloc(sizeof(struct Hash_Node*) * HASH_SIZE);
    memset((*pHashTable)->pHashHead, 0x00, sizeof(struct Hash_Node*) * HASH_SIZE);

    if (NULL == (*pHashTable)->pHashHead) return false;

    return bRet;
}

//函数二：哈希表元素插入
bool hashTableInsert(struct Hash_Table* pHashTable, double key, int value){
    int     iTablePos       = 0;
    struct Hash_Node* pNode = NULL;

    //双精度浮点数求余的系统函数 fmod
    iTablePos = (int)fmod(key,  (double)HASH_SIZE);

    if (NULL == pHashTable->pHashHead[iTablePos])
    {
        pNode = (struct Hash_Node*)malloc(sizeof(struct Hash_Node));
        pNode->key = key;
        pNode->value = value;
        pNode->pNext = NULL;
        pHashTable->pHashHead[iTablePos] = pNode;
    }
    else
    {
        pNode = pHashTable->pHashHead[iTablePos];
        while ((NULL != pNode) && (NULL != pNode->pNext))
        {
            pNode = pNode->pNext;
        }

        pNode->pNext = (struct Hash_Node*)malloc(sizeof(struct Hash_Node));
        pNode = pNode->pNext;
        pNode->key = key;
        pNode->value = value;
        pNode->pNext = NULL;
    }
    return true;
}

//函数三：将字符串数组插入哈希表中
bool pushStrsInHashTable(struct Hash_Table* pHashTable, char** strs, int strsSize){
    int         i       = 0;
    int         j       = 0;
    double      lKey    = 1;
    int         primeTable[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};      //质数列表分别对应26个英文字母
                                //a,b,c,d,e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    for (i = 0; i < strsSize; i++)
    {
        lKey    = 1;
        j = 0;
        //计算字符串的 key
        while(strs[i][j] != '\0')
        {
            lKey *= (double)primeTable[strs[i][j] - 'a'];
            j += 1;
        }

        hashTableInsert(pHashTable, lKey, i);
    }

    return true;
}

//函数四：利用哈希表将字符串数组中的字母异位词存入结果中
//哈希表中每一组链表中都可能保存了不同 key 的字符串，但是 字母异位词组合肯定在一个链表中
//运用双指针，pNode 外面循环，pNext 在链表后面找相同 key 值的字符串，找到之后避免pNode重复，拷贝后将 key=0
void groupAnagramsUseHash(char** strs, char*** pRet, struct Hash_Table* pHashTable, int* returnSize, int* pColumnSizes){
    int         i           = 0;
    int         iCurCol     = 0;
    double      lTmpKey     = 0;

    struct Hash_Node* pNode = NULL;
    struct Hash_Node* pNext = NULL;

    for (i = 0; i < HASH_SIZE; i++)
    {
        if (NULL != pHashTable->pHashHead[i])
        {
            pNode = pHashTable->pHashHead[i];
            pNext = pNode;

            while(pNode != NULL)
            {
                if (pNode->key == 0)
                {
                    pNode = pNode->pNext;
                    pNext = pNode;
                    continue;
                }

                if (lTmpKey != pNode->key)
                {
                    //发现一个新key则申请新的空间存结果
                    pRet[iCurCol] = (char**)malloc(sizeof(char*) * MAX_COL_SIZE);
                    memset(pRet[iCurCol], 0x00, sizeof(char*) * MAX_COL_SIZE);

                    iCurCol += 1;
                    lTmpKey = pNode->key;
                }

                while(pNext != NULL)
                {
                    //将链表后所有 key 值相同的 字符串拷贝到同一层结果中，为一串字母异位词
                    if (pNext->key == lTmpKey)
                    {
                        pRet[iCurCol - 1][pColumnSizes[iCurCol - 1]] = (char*)malloc(sizeof(char) * (strlen(strs[pNext->value]) + 1));
                        memset(pRet[iCurCol - 1][pColumnSizes[iCurCol - 1]], 0x00, sizeof(char) * (strlen(strs[pNext->value]) + 1));
                        memcpy(pRet[iCurCol - 1][pColumnSizes[iCurCol - 1]], strs[pNext->value], sizeof(char) * (strlen(strs[pNext->value])));

                        pColumnSizes[iCurCol - 1] += 1;
                        pNext->key = 0;
                    }
                    pNext = pNext->pNext;
                }

                pNode = pNode->pNext;
                pNext = pNode;
            }

        }
    }
    *returnSize = iCurCol;
    return;
}

//函数五：释放哈希表空间
void freeHashTable(struct Hash_Table* pHashTable){
    int     i       = 0;
    struct Hash_Node* pNode = NULL;
    struct Hash_Node* pNext = NULL;

    if (pHashTable->pHashHead != NULL)
    {
        for (i = 0; i < HASH_SIZE; i++)
        {
            pNode = pHashTable->pHashHead[i];

            while(pNode != NULL)
            {
                pNext = pNode->pNext;
                free(pNode);
                pNode = pNext;
            }
        }
        free(pHashTable->pHashHead);
    }
    return;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int                    i           = 0;
    char***                pRet        = NULL;
    struct Hash_Table*     pHashTable  = NULL;
    struct Hash_Node* pNode = NULL;

    pRet = (char***)malloc(sizeof(char**) * strsSize);
    memset(pRet, 0x00, sizeof(char**) * strsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    memset((*returnColumnSizes), 0x00, sizeof(int) * strsSize);

    //1,哈希表初始化
    hashTableInit(&pHashTable);

    //2,将字符串数字插入哈希表中
    pushStrsInHashTable(pHashTable, strs, strsSize);

/*
    for (i = 0; i < HASH_SIZE; i++)
    {
        pNode = pHashTable->pHashHead[i];

        while (NULL != pNode)
        {
            printf("[i=%d][key=%ld][val=%d][%s]\n", i, pNode->key, pNode->value, strs[pNode->value]);
            pNode = pNode->pNext;
        }
    }
*/
    //3,利用哈希表将字符串数组中的字母异位词存入结果中
    groupAnagramsUseHash(strs, pRet, pHashTable, returnSize, *returnColumnSizes);

    //4,释放哈希表空间
    freeHashTable(pHashTable);
    free(pHashTable);

    //5,返回
    return pRet;
}





/*
//方法一：
//通过26个字母的加法判定连个字符串是否是字母异位词组合，
//方法可以行，但是超时，并且没有优化的空间

//函数一：判定两字符串是否是 字母异位词组合
bool matchAnagram(char* pStr_1, int* pHash, char* pStr_2){
    int     i           = 0;
    int     j           = 0;
    int     iLen_1      = 0;
    int     iLen_2      = 0;
    bool    bFlag       = true;
    int     anagram[26];

    if ((NULL == pStr_1) || (NULL == pStr_2)) return false;

    iLen_1      = strlen(pStr_1);
    iLen_2      = strlen(pStr_2);

    if (iLen_1 != iLen_2) return false;

    memcpy(anagram, pHash, sizeof(int) * 26);

    for (j = 0; j < iLen_2; j++)
    {
        if (anagram[pStr_2[j] - 'a'] == 0)
        {
            bFlag = false;
            break;
        }
        else
        {
            anagram[pStr_2[j] - 'a'] -= 1;
        }
    }

    return bFlag;
}

//函数二：创建Hash表
//27个元素，第一个元素为字符串所有字母之和，后面26个表示 a-z的个数
void builtHash(char* pStr, int* pHash){
    int     i       = 0;
    int     iStrLen = 0;
    
    if (NULL == pStr) return;

    iStrLen = strlen(pStr);

    for (i = 0; i < iStrLen; i++)
    {
        pHash[pStr[i] - 'a'] += 1;
    }

    return;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int         i           = 0;
    int         j           = 0;
    bool        bFind       = false;
    int         iCurSize    = 0;
    char***     pRet        = NULL;
    int*        pRetCol     = NULL;
    int         iMaxSize    = strsSize;
    int**       pHash       = NULL;

    //1,初始化
    pRet = (char***)malloc(sizeof(char**) * iMaxSize);
    memset(pRet, 0x00, sizeof(char**) * iMaxSize);
    pRetCol = (int*)malloc(sizeof(int) * iMaxSize);
    memset(pRetCol, 0x00, sizeof(int) * iMaxSize);
    pHash = (int**)malloc(sizeof(int*) * iMaxSize);
    memset(pHash, 0x00, sizeof(int*) * iMaxSize);

    //2,识别 strs 中的元素
    for (i = 0; i < strsSize; i++)
    {
        for (j = 0; j < iCurSize; j++)
        {
            if (matchAnagram(pRet[j][0], pHash[j], strs[i]))
            {
                break;
            }
        }

        if (NULL == pRet[j])
        {
            pRet[j] = (char**)malloc(sizeof(char*) * iMaxSize);
            memset(pRet[j], 0x00, sizeof(char*) * iMaxSize);
            pHash[j] = (int*)malloc(sizeof(int) * 26);
            memset(pHash[j], 0x00, sizeof(int) * 26);

            builtHash(strs[i], pHash[j]);
        }

        if (NULL != strs[i])
        {
            pRet[j][pRetCol[j]] = (char*)malloc(sizeof(char) * (strlen(strs[i]) + 1));
            memset(pRet[j][pRetCol[j]], 0x00, sizeof(char) * (strlen(strs[i]) + 1));
            memcpy(pRet[j][pRetCol[j]], strs[i], sizeof(char) * (strlen(strs[i])));
        }
        pRetCol[j] += 1;
        
        if (j >= iCurSize)
        {
            iCurSize += 1;
        }
    }

    free(pHash);
    *returnSize = iCurSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}
*/
```