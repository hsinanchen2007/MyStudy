### 解题思路
跑了几次还跑出一个0ms，击败100%用户。
内存消耗9.4MB

c语言hash表实现，链表防止hash冲突。

思路是遍历数组，用`target - nums[i]`去表中查询，
+ 若查到了，则取出index；
+ 若没查到，则保存`nums[i]`进入hash 表；

供参考。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_SIZE 10000

typedef struct HashNode_ {
    int index;
    int nums;
    struct HashNode_ *next;
    struct HashNode_ *prev;
} HashNode;

typedef struct HashRow_ {
    HashNode *head;
    HashNode *tail;
} HashRow;

//global hashRow
HashRow *hashRow;

HashRow *InitHashRow(int size){
    HashRow *row;

    if (size < 0 )
        return NULL;
     
    row = (HashRow *)calloc(size, sizeof(HashRow));
    if(row == NULL)
        return NULL;
    
    return row;
}

void FreeHashRow(void){
    int i;
    HashNode *node = NULL;

    /* free the hash row and hash node*/
    if (hashRow != NULL) {
        for (i = 0; i < HASH_SIZE; i++) {
            node = hashRow[i].head;
            while (node) {
                HashNode *nextnode = node->next;
                free(node);
                node = nextnode;
            }
        }
        free(hashRow);
        hashRow = NULL;
    }
}

static inline
HashNode *GetHashNode(int nums){
    HashNode *node = NULL;
    int key;

    if(nums < 0){
        key = (nums + HASH_SIZE) % HASH_SIZE;
    } else {
        key = nums % HASH_SIZE;
    }
    HashRow *row = &hashRow[key];

    if (row->head == NULL) {
        return NULL;
    }

    node = row->head;

    while(node){
        if(node->nums == nums){
            return node;
        }
        node = node->next;
    }

    return NULL;
}

static inline
HashNode *InsertHashNode(int index, int nums){
    HashNode *node = NULL;
    HashNode *prevnode = NULL;
    int key;

    if(nums < 0){
        key = (nums + HASH_SIZE) % HASH_SIZE;
    } else {
        key = nums % HASH_SIZE;
    }
    HashRow *row = &hashRow[key];

    if (row->head == NULL) {
        node = (HashNode *)calloc(1, sizeof(HashNode));
        if(node == NULL)
            return NULL;

        node->index = index;
        node->nums = nums;

        row->head = node;
        row->tail = node;

        return node;
    }

    node = row->head;

    while(1){
        //same data nums here, just return
        if(node->nums == nums){
            //node->index = index;
            return node;
        }
        prevnode = node;
        node = node->next;
        if(node == NULL){
            //insert a new node
            node = (HashNode *)calloc(1, sizeof(HashNode));
            if(node == NULL)
                return NULL;

            node->index = index;
            node->nums = nums;

            row->tail = node;
            prevnode->next=node;
            node->prev=prevnode;

            return node;
        }
    }

    return NULL;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    HashNode *node;

    int *ret = (int *)calloc(2,sizeof(int));
    if (ret == NULL){
        *(returnSize) = 0;
        return ret;
    }

    hashRow = InitHashRow(HASH_SIZE);
    if (hashRow == NULL){
        *(returnSize) = 0;
        return ret;
    }  

    for(i = 0; i < numsSize; i++){
        node = GetHashNode(target - nums[i]);
        if (node != NULL){
            //we get target node success
            *(returnSize) = 2;
            ret[0] = node->index;
            ret[1] = i;
            break;
        }
        
        //insert current node
        node = InsertHashNode(i, nums[i]);
        if(node == NULL){
            FreeHashRow();
            *(returnSize) = 0;
            return ret;
        }
    }

    FreeHashRow();
    return ret;
}
```