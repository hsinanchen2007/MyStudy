### 解题思路
此处撰写解题思路
c的实现，好搓啊，自己实现了个2叉树
### 代码

```c
struct btree {
    int data;
    int tag;
    struct btree *lchild;
    struct btree *rchild;
};

struct btreeroot {
    long key;
    struct btree *root;
};

struct btree * insertbtree(struct btree *t, struct btree *node, long *key) {
    long tmp;
    if (t == NULL) {
        return node;
    }

    if (node->data < t->data) {
        t->lchild = insertbtree(t->lchild, node, key);
    } else {
        t->rchild = insertbtree(t->rchild, node, key);
    }

    tmp = (long)node->data - (long)t->data;
    if (tmp < 0) {
        tmp = -tmp;
    }
    if (tmp < *key) {
        *key = tmp;
    }       
        
    return t;
}

struct btree * removebtree(struct btree *t, int *nums, int tag, long *key) {
    struct btree *tmp;
    if (t == NULL) {
        return NULL;
    }

    if (t->tag == tag) {
        tmp = t;
        if (t->lchild && t->rchild) {
            t = insertbtree(t->lchild, t->rchild, key);
        } else if (t->lchild){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
        free(tmp);
        return t;
    }

    if (nums[tag] < t->data) {
        t->lchild = removebtree(t->lchild, nums, tag, key);
    } else {
        t->rchild = removebtree(t->rchild, nums, tag, key);
    }

    return t;
}

void freebt(struct btree *t) {
    if (t->lchild) {
        freebt(t->lchild);
    }

    if (t->rchild) {
        freebt(t->rchild);
    }

    free(t);
//    return 0;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    int i;
   // int *tmp = malloc(sizeof(int)* (k+1));
    int j;
    long min;
    long x;
    struct btreeroot br;
    struct btree *node;
    
    if (numsSize < 2 || k == 0) {
        return false;
    }

    if (k >= numsSize) {
        k = numsSize - 1;
    }
/*
    qsort(nums, k + 1, sizeof(int), cmp);
    for (j = 1; j <= k; j++) {
            x = (long)nums[j] - nums[j - 1];
            if (x < 0) {
                x = -x;
            }
           // x = (long)abs(x);
            if (x < min) {
                min = x;
            }
        }

        if (min <= t) {
            free(tmp);
            return true;
        }

    if (k == numsSize - 1) {
        return false;
    }
*/
    br.root = NULL;
    br.key = 11111111111;
    for (i = 0; i < numsSize; i++) {
        //memcpy(tmp, nums + i, sizeof(int)* (k+1));
        //qsort(tmp, k + 1, sizeof(int), cmp);
        node = malloc(sizeof(struct btree));
        node->lchild = node->rchild = NULL;
        node->data = nums[i];
        node->tag = i;
        br.root = insertbtree(br.root, node, &br.key);

        if (br.key <= (long)t) {
            //freebt(br.root);
            return true;
        }
        if (i >= k) {
            br.root = removebtree(br.root, nums, i - k, &br.key);
        }
    }

    //freebt(br.root);
    return false;
}
```