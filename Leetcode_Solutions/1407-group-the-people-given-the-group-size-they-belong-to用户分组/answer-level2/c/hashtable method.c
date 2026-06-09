```
#define MAX_USERS 500

typedef struct {
    int key;
    int index;
    int users[MAX_USERS];
    UT_hash_handle hh; // make this structure hashable.
} HashMap;

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    HashMap* hashMap = NULL;
    HashMap* curNode;
    int count = 0;
    int** res = (int **)malloc(sizeof(int*) * groupSizesSize);
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * groupSizesSize);

    for (int i = 0; i < groupSizesSize; i++) {
        HASH_FIND_INT(hashMap, &(groupSizes[i]), curNode);
        if (curNode == NULL) {
            if (groupSizes[i] == 1) {
                res[count] = (int*)malloc(sizeof(int));
                res[count][0] = i;
                returnColumnSizes[0][count] = 1;
                count++;
            } else {
                curNode = (HashMap*)malloc(sizeof(HashMap));
                curNode->key = groupSizes[i];
                curNode->index = 1;
                curNode->users[0] = i;
                HASH_ADD_INT(hashMap, key, curNode);
            }
        } else {
            curNode->users[curNode->index++] = i;
            if (curNode->index == curNode->key) {
                res[count] = (int*)malloc(sizeof(int) * curNode->key);
                for (int j = 0; j < curNode->key; j++) {
                    res[count][j] = curNode->users[j];
                }
                returnColumnSizes[0][count] = curNode->key;
                count++;
                HASH_DEL(hashMap, curNode);
            }
        }
    }

    *returnSize = count;

    return res;
}

```




执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 c 提交中击败了100.00% 的用户
内存消耗 :23.6 MB, 在所有 c 提交中击败了100.00%的用户