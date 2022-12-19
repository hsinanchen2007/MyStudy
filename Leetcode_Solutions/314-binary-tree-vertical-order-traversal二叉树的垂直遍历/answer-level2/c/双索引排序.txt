### 解题思路
此处撰写解题思路
节点深度（raw）作为第一优先排序索引
节点序号（index）作为第二优先排序索引

build阶段，根据节点所处的列（col），将节点存入lst中
sort阶段，对lst中的节点进行排序

输出结果


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int a_id;
    int b_id;
    int val;
} my_t;

typedef struct {
    my_t *lst;
    int n;
} head_t;

void swap(my_t *a, my_t *b) {
    my_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void my_push(head_t *root, my_t node) {
    root->lst[root->n] = node;
    root->n++;
}

void build_lst(head_t *lst_root, struct TreeNode* node, int raw, int col, int index) {
    my_t tmp_node;

    if (node == NULL) {
        return;
    }
    //printf("index = %d\n", index);
    tmp_node.val = node->val;
    tmp_node.a_id = raw;
    tmp_node.b_id = index;
    my_push(&lst_root[col], tmp_node);
    //printf("push done\n");

    build_lst(lst_root, node->left, raw + 1, col - 1, index * 2);
    build_lst(lst_root, node->right, raw + 1, col + 1, index * 2 + 1);
}

void sort(my_t *lst, int n) {
    int tmp, p;
    
    p = n - 1;
    while (p > 0) {
        tmp = 0;
        for (int i = 0; i < p; i++) {
            if (lst[i].a_id > lst[i + 1].a_id) {
                swap(&lst[i], &lst[i + 1]);
                tmp = p;
                continue;
            }
            if (lst[i].a_id == lst[i + 1].a_id) {
                if (lst[i].b_id > lst[i + 1].b_id) {
                    swap(&lst[i], &lst[i + 1]);
                    tmp = p;
                    continue;
                }
            }
        }
        p = tmp;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    head_t *lst_root;
    const int num = 20;
    int cnt;
    int **res;

    lst_root = (head_t *)malloc(sizeof(head_t) * num);
    for (int i = 0; i < num; i++) {
        lst_root[i].lst = (my_t *)malloc(sizeof(my_t) * num);
        lst_root[i].n = 0;
    }
    build_lst(lst_root, root, 0, num/2, 1);
    //printf("build done\n");
    cnt = 0;
    for (int i = 0; i < num; i++) {
        if (lst_root[i].n == 0) {
            continue;
        }
        cnt++;
    }
    res = (int **)malloc(sizeof(int *) * cnt);
    *returnSize = cnt;
    *returnColumnSizes = (int *)malloc(sizeof(int) * cnt);
    cnt = 0;
    for (int i = 0; i < num; i++) {
        if (lst_root[i].n == 0) {
            continue;
        }
        res[cnt] = (int *)malloc(sizeof(int) * lst_root[i].n);
        (*returnColumnSizes)[cnt] = lst_root[i].n;
        sort(lst_root[i].lst, lst_root[i].n);
        //printf("sort %d\n", cnt);
        for (int j = 0; j < lst_root[i].n; j++) {
            res[cnt][j] = lst_root[i].lst[j].val;
        }
        cnt++;
    }
    return res;
}
```