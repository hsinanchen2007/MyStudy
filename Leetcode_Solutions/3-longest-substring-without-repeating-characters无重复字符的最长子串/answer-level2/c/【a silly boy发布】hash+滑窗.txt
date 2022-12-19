![5DB3E020-27AE-48F1-BFE5-256CB3C90DFB.jpeg](https://pic.leetcode-cn.com/3d4efcb9773a91356fd12329db6a472f6d524d6f17c003272644322bd4a36d8e-5DB3E020-27AE-48F1-BFE5-256CB3C90DFB.jpeg)

```
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashNode;

HashNode *g_this = NULL;

bool IsHaveSameChar(char *s, int end) {
    int i;
    HashNode *tmpHashNode;
    bool isHaveSameChar = false;
    int key;

    key = s[end];
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
        tmpHashNode->key = key;
        tmpHashNode->val = 0;
        tmpHashNode->val++;
        HASH_ADD_INT(g_this, key, tmpHashNode);
    } else {
        isHaveSameChar = true;
    }

    return isHaveSameChar;
}

bool HashFindSameChar(char *s, int end) {
    int key;
    HashNode *tmpHashNode;

    key = s[end];
    HASH_FIND_INT(g_this, &key, tmpHashNode);
    if (tmpHashNode == NULL) {
        return false;
    } else {
        return true;
    }
}

void HashAddChar(char *s, int end) {
    HashNode *tmpHashNode;
    int key;

    key = s[end];
    tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
    tmpHashNode->key = key;
    HASH_ADD_INT(g_this, key, tmpHashNode);
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

int lengthOfLongestSubstring(char * s)
{
    int lenS = strlen(s);
    int start = 0;
    int end = 0;
    int returnVal = 0;
    HashNode *tmpHashNode;
    int key;
    while (end < lenS) {
        while ((end < lenS) && (HashFindSameChar(s, end) == false)) {
            HashAddChar(s, end);
            end++;
            if (returnVal < (end - start)) {
                returnVal = end - start;
            }
        }
        //printf("end: %d, start: %d, returnVal: %d\n", end, start, returnVal);
        key = s[start];
        HASH_FIND_INT(g_this, &key, tmpHashNode);
        if (tmpHashNode != NULL) {
            HASH_DEL(g_this, tmpHashNode);
            free(tmpHashNode);
            tmpHashNode = NULL;
        }
        start++;
    }

__END__:
    ResetHashNode();
    if (tmpHashNode != NULL) {
        free(tmpHashNode);
    }

    return returnVal;
}
```
