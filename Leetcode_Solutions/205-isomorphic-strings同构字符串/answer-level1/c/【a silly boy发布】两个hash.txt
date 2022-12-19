![546A3295-2EEA-4411-B0C8-BAA6A2475386.jpeg](https://pic.leetcode-cn.com/381b9b4e32ab900df071eaf3a8c431db81f9ab5fd438dc31336db8779052589e-546A3295-2EEA-4411-B0C8-BAA6A2475386.jpeg)

```
struct HashEntry1 {
    int key;
    int val;
    UT_hash_handle hh;
};
struct HashEntry1 *g1_this = NULL;

struct HashEntry2 {
    int key;
    int val;
    UT_hash_handle hh;
};
struct HashEntry2 *g2_this = NULL;

bool isIsomorphic(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    bool returnVal = true;
    int i;
    struct HashEntry1 *tmpHashEntry1;
    int key1;
    struct HashEntry1 *current1;
    struct HashEntry1 *tmp1;

    struct HashEntry2 *tmpHashEntry2;
    int key2;
    struct HashEntry2 *current2;
    struct HashEntry2 *tmp2;

    for (i = 0; i < tLen; i++) {
        key1 = t[i];
        HASH_FIND_INT(g1_this, &key1, tmpHashEntry1);
        if (tmpHashEntry1 == NULL) {
            tmpHashEntry1 = (struct HashEntry1 *)malloc(sizeof(struct HashEntry1));
            tmpHashEntry1->key = t[i];
            tmpHashEntry1->val = s[i];
            HASH_ADD_INT(g1_this, key, tmpHashEntry1);
        } else {
            if (tmpHashEntry1->val != s[i]) {
                returnVal = false;
                goto _END_;
            }
        }
    }

    for (i = 0; i < sLen; i++) {
        key2 = s[i];
        HASH_FIND_INT(g2_this, &key2, tmpHashEntry2);
        if (tmpHashEntry2 == NULL) {
            tmpHashEntry2 = (struct HashEntry2 *)malloc(sizeof(struct HashEntry2));
            tmpHashEntry2->key = s[i];
            tmpHashEntry2->val = t[i];
            HASH_ADD_INT(g2_this, key, tmpHashEntry2);
        } else {
            if (tmpHashEntry2->val != t[i]) {
                returnVal = false;
                goto _END_;
            }
        }
    }

    _END_:

    HASH_ITER(hh, g1_this, current1, tmp1) {
        HASH_DEL(g1_this, current1);
        free(current1);
    }

    HASH_ITER(hh, g2_this, current2, tmp2) {
        HASH_DEL(g2_this, current2);
        free(current2);
    }

    return returnVal;
}
```
