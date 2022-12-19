```C
typedef struct {
    int* nums;
    int numsSize;
    int* numsIndex;
    int* tree;
    int treeSize;
} SegmentTree;
void build_tree(SegmentTree* tree, int node, int start, int end){
    if (start == end) {
        tree->tree[node] = tree->nums[start];
        tree->numsIndex[start] = node;
        return;
    }
    int mid = start + (end - start) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    build_tree(tree, left_node, start, mid);
    build_tree(tree, right_node, mid + 1, end);
    tree->tree[node] = tree->tree[left_node] + tree->tree[right_node];
}
SegmentTree* createTree(int* nums, int numsSize){
    if (numsSize <= 0) {
        return NULL;
    }
    SegmentTree* tree = (SegmentTree*)malloc(sizeof(SegmentTree));
    tree->nums = nums;
    tree->numsSize = numsSize;
    tree->numsIndex = (int*)malloc(sizeof(int) * numsSize);
    tree->treeSize =  numsSize * 3;
    tree->tree = (int*)malloc(sizeof(int) * tree->treeSize);
    memset(tree->tree, 0x00, sizeof(int) * tree->treeSize);
    build_tree(tree, 0, 0, numsSize - 1);
    return tree;
}
void freeTree(SegmentTree* tree){
    if (tree != NULL) {
        free(tree->numsIndex);
        free(tree->tree);
        free(tree);        
    }
}
void update_tree(SegmentTree* tree, int pos, int value){
    tree->nums[pos] = value;
    int index = tree->numsIndex[pos];
    tree->tree[index] = value;
    while (index != 0) {
        if (index % 2 == 0) {
            index = (index - 1) / 2;
        } else {
            index = index / 2;
        }
        tree->tree[index] = tree->tree[index * 2 + 1] + tree->tree[index * 2 + 2];
    }
}
int query_tree(SegmentTree* tree, int node, int start, int end, int left, int right){
    if (right < start || left > end)
        return 0;
    else if (left <= start && end <= right)
        return tree->tree[node];
    else if (start == end)
        return tree->tree[node];
    int mid = start + (end - start) / 2;
    int left_node = node * 2 + 1;
    int right_node = node * 2 + 2;
    int sum_left = query_tree(tree, left_node, start, mid, left, right);
    int sum_right = query_tree(tree, right_node, mid + 1, end, left, right);
    return sum_left + sum_right;
}
typedef struct {
    SegmentTree* tree;
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize){
    NumArray* obj = (NumArray *)malloc(sizeof(NumArray));
    obj->tree = createTree(nums, numsSize);
    return obj;
}
void numArrayUpdate(NumArray* obj, int i, int val){
    update_tree(obj->tree, i, val);
}
int numArraySumRange(NumArray* obj, int i, int j){
    return query_tree(obj->tree, 0, 0, obj->tree->numsSize - 1, i, j);
}
void numArrayFree(NumArray* obj){
    freeTree(obj->tree);
    free(obj);
}
```
