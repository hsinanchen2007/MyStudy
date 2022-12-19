![927676B8-655B-44AE-9274-EAE9194AF7FE.jpeg](https://pic.leetcode-cn.com/1631b74d6f4adf303b763d7fe69848fc582f9b48bac29deef4100d6eb15a02f9-927676B8-655B-44AE-9274-EAE9194AF7FE.jpeg)

```
typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
} HashNode;

HashNode *g_this = NULL;

#define LIDU 10

void ResetHashNode()
{
    HashNode *current;
    HashNode *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }
}

bool HashFindHashNode(int num) 
{
    int key;
    HashNode *tmpHashNode;
    key = num;
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
        tmpHashNode->key = key;
        tmpHashNode->cnt = 0;
        tmpHashNode->cnt++;
        HASH_ADD_INT(g_this, key, tmpHashNode);
        return false;
    } else {
        return true;
    }
}

bool ReturnVal(bool isHave) 
{
    if (isHave == true) {
        return false;
    } else {
        return true;
    }
}

bool isHappy(int n)
{
    int splitYuNum;
    int rebuildNum;
    int nCpy = n;
    bool isHave;
    int key;
    while (nCpy != 1) {
        rebuildNum = 0;
        isHave = HashFindHashNode(nCpy);
        if (isHave == true) {
            break;
        }
        while (nCpy != 0) {
            splitYuNum = nCpy % LIDU;
            rebuildNum = rebuildNum + splitYuNum * splitYuNum;
            nCpy = nCpy / LIDU;
        }
        nCpy = rebuildNum;
    }

    ResetHashNode();

    return ReturnVal(isHave);
}
```
