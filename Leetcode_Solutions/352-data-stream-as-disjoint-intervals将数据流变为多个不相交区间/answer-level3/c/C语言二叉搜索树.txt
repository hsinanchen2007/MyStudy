### 解题思路
C语言二叉搜索树，没有借助任何库函数，如果加上自平衡的话效率应该会更高。

### 代码

```c
//////////////////////////////////////////////////////////////////////
//kongconf 2020-03-20
//////////////////////////////////////////////////////////////////////
typedef struct Tnode {
    int start, end;
    struct Tnode* left, * right;
}Tnode;

typedef struct {
    int cnt;
    Tnode* root;
} SummaryRanges;

Tnode* createTnode(int start, int end) {
    Tnode* n = (Tnode*)malloc(sizeof(Tnode));
    n->start = start, n->end = end;
    n->left = n->right = 0;
    return n;
}

SummaryRanges* summaryRangesCreate() {
    SummaryRanges* sr = (SummaryRanges*)malloc(sizeof(SummaryRanges));
    sr->cnt = 0;
    sr->root = 0;
    return sr;
}

Tnode* dfsAdd(SummaryRanges* obj, Tnode* root, int val) {
    if (root == NULL) {
        obj->cnt++;
        return createTnode(val, val);
    }
    else if (val >= root->start && val <= root->end) {
        return root;
    }
    else if (val == root->start - 1) {
        root->start = val;
        if (root->left && val == root->left->end + 1) {
            root->start = root->left->start;
            Tnode* n = root->left;
            root->left = root->left->left;
            obj->cnt--;
            free(n);
        }
        else if (root->left && root->left->right) {
            Tnode* n = root->left;
            while (n->right->right) {
                n = n->right;
            }
            if (val == n->right->end + 1) {
                root->start = n->right->start;
                Tnode* t = n->right;
                n->right = n->right->left;
                obj->cnt--;
                free(t);

            }
        }
    }
    else if (val == root->end + 1) {
        root->end = val;
        if (root->right && val == root->right->start - 1) {
            root->end = root->right->end;
            Tnode* n = root->right;
            root->right = root->right->right;
            obj->cnt--;
            free(n);
        }
        else if (root->right && root->right->left) {
            Tnode* n = root->right;
            while (n->left->left) {
                n = n->left;
            }
            if (val == n->left->start - 1) {
                root->end = n->left->end;
                Tnode* t = n->left;
                n->left = n->left->right;
                obj->cnt--;
                free(t);
            }
        }
    }
    else if (val < root->start - 1) {
        root->left = dfsAdd(obj, root->left, val);
    }
    else {
        root->right = dfsAdd(obj, root->right, val);
    }
    return root;
}

void summaryRangesAddNum(SummaryRanges* obj, int val) {
    obj->root = dfsAdd(obj, obj->root, val);
}

void dfsSearch(Tnode* root, int** res, int* size) {
    if (root == NULL) return;
    dfsSearch(root->left, res, size);
    res[*size][0] = root->start;
    res[*size][1] = root->end;
    (*size)++;
    dfsSearch(root->right, res, size);
}

int** summaryRangesGetIntervals(SummaryRanges* obj, int* retSize, int** retColSize) {
    if (obj->cnt == 0) {
        *retSize = 0;
        return NULL;
    }
    int** res = (int**)malloc(obj->cnt * sizeof(int*));
    int* colsize = (int*)malloc(obj->cnt * sizeof(int));
    for (int i = 0; i < obj->cnt; ++i) {
        colsize[i] = 2;
        res[i] = (int*)malloc(2 * sizeof(int));
    }
    int size = 0;
    dfsSearch(obj->root, res, &size);
    *retSize = obj->cnt;
    *retColSize = colsize;
    return res;
}

void dfsFree(Tnode* root) {
    if (root == NULL) return;
    dfsFree(root->left);
    dfsFree(root->right);
    free(root);
}

void summaryRangesFree(SummaryRanges* obj) {
    dfsFree(obj->root);
    free(obj);
}
//////////////////////////////////////////////////////////////////////
```