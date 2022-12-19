![81671EF1-922D-45BE-B953-6A4136D8C3ED.jpeg](https://pic.leetcode-cn.com/f22d157a9654369b921cc231e802210b7c48d5e905262cdcd106a3e3ef620aca-81671EF1-922D-45BE-B953-6A4136D8C3ED.jpeg)

```
//滑动窗口 + hash
typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
} HashNode;

HashNode *g_this = NULL;

bool FindHashNodeSameChar(char c)
{
    HashNode *tmpHashNode;
    int key = c;
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        return false;
    } else {
        return true;
    }
}

void AddHashNodeChar(char c)
{
    HashNode *tmpHashNode;
    int key = c;
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
        tmpHashNode->key = key;
        tmpHashNode->cnt = 0;
        tmpHashNode->cnt++;
        HASH_ADD_INT(g_this, key, tmpHashNode);
    } else {
        tmpHashNode->cnt++;
    }
}

void DelHashNodeChar(char c)
{
    HashNode *tmpHashNode;
    int key = c;
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    HASH_DEL(g_this, tmpHashNode);
    free(tmpHashNode);
}

void ResetHashNode()
{
    HashNode *current;
    HashNode *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }
}

int numKLenSubstrNoRepeats(char * S, int K)
{
    int lenS = strlen(S);
    int start = 0;
    int end = 0;
    int returnCnt = 0;
    int tmpCnt = 0;
    while (end < lenS) {
        while ((end < lenS) && (FindHashNodeSameChar(S[end]) == false)) {
            AddHashNodeChar(S[end]);
            end++;
            tmpCnt++;
            if (tmpCnt == K) {
                returnCnt++;
                break;
            }
        }
        //printf("start: %d, end: %d\n", start, end);
        DelHashNodeChar(S[start]);       
        start++;
        tmpCnt--;
    }

    ResetHashNode();
    return returnCnt;
}
```
