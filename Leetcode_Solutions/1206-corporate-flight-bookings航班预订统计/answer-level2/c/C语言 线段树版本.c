利用线段树的 `lazytag`来解决问题, 复杂度 O(nlogn)。 （不需要PUSH_UP宏， 因为不需要求区间最值、区间求和）

```c
// 4倍空间大小
#define SEGMENT_TREE_SIZE 40020

// 线段树存储的数据值类型, 方便修改
#define DATA_TYPE long long

typedef struct {
    DATA_TYPE num;              // 可以是最值或者区间和, 修改PUSH_UP以及查询函数
    DATA_TYPE lazy;
    int left;
    int right;
} SegmentTreeNode;

typedef struct {
    SegmentTreeNode arr[SEGMENT_TREE_SIZE];
} SegmentTree;

// #define PUSH_UP(tree_, index_) \
//     ((tree_)->arr[(index_) << 1].num + (tree_)->arr[(index_) << 1 | 1].num)
// #define PUSH_UP(tree_, index_) MAX((tree_)->arr[(index_) << 1].num, (tree_)->arr[(index_) << 1 | 1].num)
// #define PUSH_UP(tree_, index_) MIN((tree_)->arr[(index_) << 1].num, (tree_)->arr[(index_) << 1 | 1].num)
#define LAZY_UPGRADE(tree_, index_, left_, right_, new_) do {                               \
    (tree_)->arr[(index_)].lazy += (new_);                                                  \
    (tree_)->arr[(index_)].num += (new_) * ((right_) - (left_) + 1);                        \
} while(0)
#define PUSH_DOWN(tree_, index_, left_, right_) do {                                        \
    int mid = (left_ + right_) / 2;                                                         \
    LAZY_UPGRADE((tree_), (index_) << 1, left_, mid, (tree_)->arr[(index_)].lazy);          \
    LAZY_UPGRADE((tree_), (index_) << 1 | 1, mid + 1, right_, (tree_)->arr[(index_)].lazy); \
    (tree_)->arr[(index_)].lazy = 0;                                                        \
} while(0)

void SegmentTreeClear(SegmentTree* tree)
{
    memset(tree, 0, sizeof(SegmentTree));
}

void SegmentTreeBuild(SegmentTree* tree, DATA_TYPE* arr, uint32_t index, int l, int r) {
    tree->arr[index].left = l;
    tree->arr[index].right = r;

    if (l == r) {
        if (arr == NULL) {
            tree->arr[index].num = 0;
        } else {
            tree->arr[index].num = arr[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    SegmentTreeBuild(tree, arr, index << 1, l, mid);
    SegmentTreeBuild(tree, arr, index << 1 | 1, mid + 1, r);
    // tree->arr[index].num = PUSH_UP(tree, index);
    return;
}

void SegmentTreeModifySection(SegmentTree* tree, uint32_t index, int l, int r, DATA_TYPE k) {
    if (l <= tree->arr[index].left && tree->arr[index].right <= r) {
        LAZY_UPGRADE(tree, index, tree->arr[index].left, tree->arr[index].right, k);
        return ;
    }

    PUSH_DOWN(tree, index, tree->arr[index].left, tree->arr[index].right);
    if (tree->arr[index << 1].right >= l) {
        SegmentTreeModifySection(tree, index << 1, l, r, k);
    }
    if (tree->arr[index << 1 | 1].left <= r) {
        SegmentTreeModifySection(tree, index << 1 | 1, l, r, k);
    }
    // tree->arr[index].num = PUSH_UP(tree, index);
    return;
}

DATA_TYPE SegmentTreeQuerySection(SegmentTree* tree, uint32_t index, int l, int r) {
    int res = 0;
    int childQuery;
    if (l <= tree->arr[index].left && tree->arr[index].right <= r) {
        return tree->arr[index].num;
    }
    PUSH_DOWN(tree, index, tree->arr[index].left, tree->arr[index].right);
    if (tree->arr[index << 1].right >= l) {
        childQuery = SegmentTreeQuerySection(tree, index << 1, l, r);
        res += childQuery;
    }
    if (tree->arr[index << 1 | 1].left <= r) {
        childQuery = SegmentTreeQuerySection(tree, index << 1 | 1, l, r);
        res += childQuery;
    }
    return res;
}

#define SEGEMENT_BUILD(tree_, arr_, l_, r_) SegmentTreeBuild(tree_, arr_, 1, l_, r_)
#define SEGEMENT_MODIFY(tree_, l_, r_, k_) SegmentTreeModifySection(tree_, 1, l_, r_, k_)
#define SEGEMENT_QUERY(tree_, l_, r_) SegmentTreeQuerySection(tree_, 1, l_, r_)

SegmentTree g_tree;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    if (bookings == NULL || bookingsSize == 0 || bookingsColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }
    SegmentTreeClear(&g_tree);
    SEGEMENT_BUILD(&g_tree, NULL, 1, n);
    
    for (int i = 0; i < bookingsSize; ++i) {
        SEGEMENT_MODIFY(&g_tree, bookings[i][0], bookings[i][1], bookings[i][2]);
    }
    
    int* ret = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    for (int i = 1; i <= n; ++i) {
        ret[i - 1] = SEGEMENT_QUERY(&g_tree, i, i);
    }
    return ret;
}

```