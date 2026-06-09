发现面试宝典上面的题，和leetcode原本的题目的最大区别就是，面试宝典上面的题，每次要求的是ascii所有的字符，leetcode上面一般是alphabet。
```
typedef struct {
    int key;
    int counts;
    UT_hash_handle hh;
}HashMap;

bool isUnique(char* astr){
    HashMap* hashMap = NULL;
    HashMap* node;
    int value;
    bool res = true;

    for (int i = 0, length = strlen(astr); i < length; i++) {
        value = astr[i];
        HASH_FIND_INT(hashMap, &value, node);
        if (node == NULL) {
            node = (HashMap*)malloc(sizeof(HashMap));
            node->key = value;
            HASH_ADD_INT(hashMap, key, node);
        } else {
            res = false;
            break;
        }
    }

    return res;
}
```
