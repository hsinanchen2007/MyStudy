## c++ 排名 时间击败100%，空间击败100%的算法

用链表结构实现hash，同时用链表存储数据


先定义链表结构
```
typedef struct hashLinkNode {
    int key;
    int value;
    struct hashLinkNode *sameHash;

    struct hashLinkNode *nextLink;
} HashLinkNode;
```

```
#define NOT_EXIST -1

class TwoSum {

private:
    const int cHashSeed = 4096;
    HashLinkNode **hashTable;
    HashLinkNode *rootNode;
    int nodeCount;

    HashLinkNode* putValueForKeyInHashTable(int key, int value) {

        int hash = key % cHashSeed;
        hash = (hash >= 0) ? hash : (hash + cHashSeed);

        HashLinkNode *p = hashTable[hash];

        HashLinkNode *temp = new HashLinkNode();
        temp->key = key;
        temp->value = value;
        temp->sameHash = p;
        temp->nextLink = NULL;

        hashTable[hash] = temp;

        return temp;
    }

    int getValueForKeyInHashTable(int key) {
        if (hashTable == NULL) return NOT_EXIST;

        int hash = key % cHashSeed;
        hash = (hash >= 0) ? hash : (hash + cHashSeed);

        HashLinkNode *p = hashTable[hash];
        while (p != NULL) {
            if (p->key == key) {
                return p->value;
            }
            p = p->sameHash;
        }

        return NOT_EXIST;
    }

public:
    /** Initialize your data structure here. */
    TwoSum() {

        hashTable = new HashLinkNode*[cHashSeed];
        for (int i = 0; i < cHashSeed; ++i) {
            hashTable[i] = NULL;
        }
        rootNode = NULL;
        nodeCount = 0;
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        HashLinkNode *node = putValueForKeyInHashTable(number, nodeCount++);
        node->nextLink = rootNode;
        rootNode = node;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {

        for (HashLinkNode *p = rootNode; p != NULL; p = p->nextLink) {
            int i = getValueForKeyInHashTable(value - p->key);
            if (i != NOT_EXIST  && i != p->value ) return  true;
        }

        return false;
    }
};
```
