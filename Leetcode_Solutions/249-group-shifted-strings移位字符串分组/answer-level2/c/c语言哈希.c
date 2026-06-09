c语言哈希题解，没有容器费劲啊
#define true 1
#define false 0
#define MAX_CH_NUM 26
#define MAX_STR_LEN 256
#define memset_s(a,b,c,d) memset(a, c, d)
#define memcpy_s(a,b,c,d) memcpy(a, c, d)

struct MyHash {
    char name[MAX_STR_LEN];
    int strCnt;
    char **strList;
    UT_hash_handle hh;
};
struct MyHash *hashList = NULL;

void AddHashNode(char *word, int len)
{
    struct MyHash *node;

    node = (struct MyHash *)malloc(sizeof(struct MyHash));
    memset_s(node, sizeof(struct MyHash), 0, sizeof(struct MyHash));
    memcpy_s(node->name, strlen(word), word, strlen(word));
    node->strList = (char **)malloc(sizeof(char **) * len);
    for (int i = 0; i < len; i++) {
        node->strList[i] = (char *)malloc(sizeof(char) * MAX_STR_LEN);
        memset_s(node->strList[i], MAX_STR_LEN, 0, MAX_STR_LEN);
    }
    memcpy_s(node->strList[node->strCnt++], strlen(word), word, strlen(word));
    HASH_ADD_STR(hashList, name, node);
}

struct MyHash *FindHashNode(char *word)
{
    struct MyHash *node = NULL;

    HASH_FIND_STR(hashList, word, node);

    return node;
}

void AddHashNodeElement(struct MyHash *node, char *word)
{
    memcpy_s(node->strList[node->strCnt++], strlen(word), word, strlen(word));
}

void DestoryHash()
{
    struct MyHash *node, *tmp;

    HASH_ITER(hh, hashList, node, tmp) {
        HASH_DEL(hashList, node);
        for (int i = 0; i < node->strCnt; i++) {
            free(node->strList[i]);
        }
        free(node->strList);
        free(node);
    }
}

int IsWordMoveSame(char *word1, char *word2)
{
    int i;
    int delta = -1;
    int tmpDelta;
    int len1, len2;
    int num1, num2;

    len1 = strlen(word1);
    len2 = strlen(word2);
    if (len1 != len2) {
        return false;
    }
    if (len1 == 1 && len2 == 1) {
        return true;
    }

    for (i = 0; i < len1; i++) {
        num1 = word1[i] - 'a';
        num2 = word2[i] - 'a';    
        tmpDelta = (num1 >= num2) ? (num1 - num2) : (num1 + MAX_CH_NUM - num2);    
        if ((delta != -1) && (tmpDelta != delta)) {
            return false;
        }
        delta = tmpDelta;
    }

    return true;
}

char *** groupStrings(char ** strings, int stringsSize, int* returnSize, int** returnColumnSizes){
    int i, j;
    int len;
    int index = 0;
    int curFlag;
    int *visited;
    char ***results;
    int *resultSizes;
    int resultSize = 0;
    struct MyHash *node = NULL, *tmp;

    visited = (int *)malloc(sizeof(int) * stringsSize);
    memset_s(visited, sizeof(int) * stringsSize, 0, sizeof(int) * stringsSize);

    for (i = 0; i < stringsSize; i++) {
        if (visited[i] == 0) {
            resultSize += 1;
            AddHashNode(strings[i], stringsSize);
            for (j = i + 1; j < stringsSize; j++) {
                curFlag = false;
                if (visited[j] == 0) {
                    curFlag = IsWordMoveSame(strings[i], strings[j]);
                    if (curFlag == true) {
                        node = FindHashNode(strings[i]);
                        if (node != NULL) {
                            AddHashNodeElement(node, strings[j]);
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
    }

    *returnSize = resultSize;
    resultSizes = (int *)malloc(sizeof(int) * resultSize);
    results = (char ***)malloc(sizeof(char **) * resultSize);
    HASH_ITER(hh, hashList, node, tmp) {
        resultSizes[index] = node->strCnt;
        results[index] = (char **)malloc(sizeof(char *) * node->strCnt);
        for (i = 0; i < node->strCnt; i++) {
            len = strlen(node->strList[i]);
            results[index][i] = (char *)malloc(sizeof(char) * (len + 1));
            memset_s(results[index][i], len + 1, 0, len + 1);
            memcpy_s(results[index][i], len, node->strList[i], len);
        }
        index += 1;
    }

    DestoryHash();

    *returnColumnSizes = resultSizes;

    return results;
}