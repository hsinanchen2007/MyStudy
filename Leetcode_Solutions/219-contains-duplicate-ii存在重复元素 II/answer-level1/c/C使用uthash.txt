不废话，上代码

```
struct myStru {
    int key;
    int val;
    UT_hash_handle hh;
};
void data_add(struct myStru** table, int key, int val) {
    struct myStru* s = calloc(1, sizeof(struct myStru));
    s->key = key;
    s->val = val;
    HASH_ADD_INT(*table, key, s);
}
struct myStru* data_find(struct myStru** table, int key) {
    struct myStru* s = NULL;
    HASH_FIND_INT(*table, &key, s);
    return s;
}
void data_del(struct myStru** table, struct myStru* s) {
    HASH_DEL(*table, s);
    free(s);
}
void data_free(struct myStru** table) {
    struct myStru *cur, *tmp;
    HASH_ITER(hh, *table, cur, tmp) {
        HASH_DEL(*table, cur);
        free(cur);
    }
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct myStru* table = NULL;

    for(int i = 0; i < numsSize; i++) {
        int key = nums[i];
        int val = i;
        struct myStru* s = data_find(&table, key);
        if (s && abs(s->val - i) <= k) { // find and ok
            data_free(&table);
            return true;
        }
        if (s) { // find and not ok, delete it
            data_del(&table, s);
        }
        data_add(&table, key, val); // add new always
    }
    data_free(&table);
    return false;
}
```
