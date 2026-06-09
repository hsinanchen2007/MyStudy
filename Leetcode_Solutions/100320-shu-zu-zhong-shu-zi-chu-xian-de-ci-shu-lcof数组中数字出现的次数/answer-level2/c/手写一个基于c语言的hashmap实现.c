### 解题思路
1 手写一个hashmap
2 重复的key移除
3 剩余hashmap中的两个key就是要求的key

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct JJHashTableNode {
    int hashKeyValue; //hash值
    int hashKeyModeValue; //hash除以模之后的值
    char *str;
    int value;
    struct JJHashTableNode *next;
} JJHashTableNode;

typedef struct JJHashTableS {
    int arraySize ;//大小
    JJHashTableNode **array;//数组
} JJHashTableS;
JJHashTableS *createTable(int size) {
    if (size == 0) {
        return NULL;
    }
    JJHashTableS *table = malloc(sizeof(struct JJHashTableS));
    table->arraySize = size;
    table->array = malloc(sizeof(struct JJHashTableNode *) *size);
    memset(table->array, 0, sizeof(struct JJHashTableNode*)*size);
    return table;
}

int zHash(char *str) {
    
    if (str == NULL || strlen(str) <=0 ) {
        return -1;//说明错误
    }
    int hash = 0;
    int i = 0;
    while (str[i] != '\0') {
        hash = 31 *str[i] + hash;
        i++;
    }
    return  hash> 0 ? hash : -hash;
}

void setValue(JJHashTableS *table, char *str, int value) {
    if (table == NULL) {
        return;
    }
    int hashValue = zHash(str);
    if (hashValue < 0) {
        return;
    }
    int modHashValue = hashValue % table->arraySize;
    
    JJHashTableNode *node = table->array[modHashValue];
    
    if (node == NULL) {
        JJHashTableNode *node = (JJHashTableNode *)malloc(sizeof(struct JJHashTableNode));
        node->value = value;
        node->next = NULL;
        node->str = str;
        node->hashKeyValue = hashValue;
        node->hashKeyModeValue = hashValue % table->arraySize;
        table->array[modHashValue] = node;
    }
    else {
        
        JJHashTableNode *tmpNode = node;
        JJHashTableNode *lastNode = node;
        bool findSameHashKey = false;
        while (tmpNode != NULL) {
            lastNode = tmpNode;
            if (0 == strcmp(str, tmpNode->str)) {
                tmpNode->value = value;
                findSameHashKey = true;
                break;
            }
            tmpNode = tmpNode->next;
        }
        
        if (!findSameHashKey) {
            JJHashTableNode *node = (JJHashTableNode *)malloc(sizeof(struct JJHashTableNode));
            node->value = value;
            node->next = NULL;
            node->str = str;
            node->hashKeyValue = hashValue;
            node->hashKeyModeValue = hashValue % table->arraySize;
            lastNode->next = node;
        }
    }
}

JJHashTableNode * getValue(JJHashTableS *table, char *str) {
    if (table == NULL) {
        return NULL;
    }
    int hashValue = zHash(str);
    if (hashValue < 0) {
        return NULL;
    }
    int modHashValue = hashValue % table->arraySize;
    JJHashTableNode *node = table->array[modHashValue];
    if (node == NULL) {
        return NULL;
    }
    else {
        JJHashTableNode *tmpNode = node;
        while (tmpNode != NULL) {
            if (0 == strcmp(str, tmpNode->str)) {
                return tmpNode;
                break;
            }
            tmpNode = tmpNode->next;
        }
    }
    return NULL;
}

void removeKey(JJHashTableS *table, char *str) {
    
    if (table == NULL) {
        return;
    }
    int hashValue = zHash(str);
    if (hashValue < 0) {
        return;
    }
    int modHashValue = hashValue % table->arraySize;
    JJHashTableNode *node = table->array[modHashValue];
    
    if (node != NULL) {
        JJHashTableNode *tmpNode = node;
        JJHashTableNode *tmpNextNode = tmpNode->next;
        if (0 == strcmp(str, tmpNode->str)) {
            table->array[modHashValue] = tmpNextNode;
            free(tmpNode);
            return;
        }
        
        while (tmpNextNode != NULL) {
            if (0 == strcmp(str, tmpNextNode->str)) {
                JJHashTableNode *nextNode = tmpNextNode->next;
                if (nextNode != NULL) {
                    tmpNode->next = nextNode;
                    free(tmpNextNode);
                }
                else {
                    tmpNode->next = NULL;
                    free(tmpNextNode);
                }
                break;
            }
            tmpNode = tmpNode->next;
            tmpNextNode = tmpNode->next;
        }
    }
}

bool hasKey(JJHashTableS *table, char *str) {
    if (table == NULL) {
        return false;
    }
    int hashValue = zHash(str);
    if (hashValue < 0) {
        return false;
    }
    int modHashValue = hashValue % table->arraySize;
    JJHashTableNode *node = table->array[modHashValue];
    while (node) {
        if (strcmp(node->str, str) == 0) {
            return true;
        }
        node = node->next;
    }
    return false;
}

char **keys(JJHashTableS *table, int* keysCount) {
    if (table == NULL) {
        return NULL;
    }
    int topKeysCount = 0;
    char **str =(char **) malloc(sizeof(char *) * table->arraySize);
    for (int i = 0; i< table->arraySize; i++) {
        JJHashTableNode *node = table->array[i];
        while (node) {
            str[topKeysCount] = node->str;
            topKeysCount ++;
            node = node->next;
        }
    }
    
    *keysCount = topKeysCount;
    return str;
}

int* singleNumbers(int* nums, int numsSize, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    JJHashTableS *table = createTable(100);
    for(int i = 0;i< numsSize;i++) {
        int value = nums[i];
        char *key = malloc(sizeof(char *) *5);
        sprintf(key, "%d", value);
        if (hasKey(table, key)) {
            removeKey(table, key);
        }
        else {
            setValue(table, key,1);
        }
    }

    int keysCount;
    char **result =  keys(table, &keysCount);
    if (keysCount) {
        int *array = malloc(sizeof(int) *2);
        array[0] = atoi(result[0]);
        array[1] = atoi(result[1]);
        *returnSize = 2;
        return  array;
    }
    *returnSize = 0;
    return NULL;
}
```