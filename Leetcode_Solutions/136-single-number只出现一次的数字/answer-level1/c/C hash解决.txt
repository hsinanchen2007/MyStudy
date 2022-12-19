### 解题思路
数组元素作为key 数组个数作为cnt 找到cnt=1的那个key既为最终值

### 代码

```c
typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
}*hashmap;

//遍历数组， 数组元素作为key 数组个数作为cnt 找到cnt=1的那个key既为最终值
//  * 输入: [2,2,1]
//  * 输出: 1
int singleNumber(int* nums, int numsSize) {
    hashmap hashTable = NULL;
    hashmap node = NULL;
    int i;
    int ret;
    for (i = 0; i < numsSize; i++) {
        if(hashTable) {
            HASH_FIND_INT(hashTable,&nums[i],node);
        }
        if(!node) { //node为空
            node = (hashmap)malloc(sizeof(*node));
            node->key = nums[i];
            node->value = 1;
            HASH_ADD_INT(hashTable,key,node);
        } else {
            node->value++;
        }
    }
    hashmap a,tmp;
    HASH_ITER(hh, hashTable, a, tmp) {
        if (a->value == 1) {
            ret = a->key;
        }
    }
    return ret;   
}
```