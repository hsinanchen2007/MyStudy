```
typedef struct {
    struct TreeNode *root;
    int left;   // 标记当前节点的左节点已经遍历过
    int right;  // 标记当前节点的右节点已经遍历过
 }STACK;
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    const int capacity = 1000;
    int *res = malloc(sizeof(int) * capacity);
    *returnSize = 0;
    STACK base[capacity];
    memset(base, 0, sizeof(STACK) * capacity);
    int index = 0;

    base[index].root = root;
    index++;

    while(index != 0) {
        if (base[index - 1].root->left == NULL || base[index - 1].left != 0) {   // 无左子节点，处理右子节点
            if (base[index - 1].root->right == NULL || base[index - 1].right != 0) { // 左右均无子节点 弹出栈值
                res[(*returnSize)++] = base[index - 1].root->val;
                base[index - 1].left = 0;
                base[index - 1].right = 0;
                index--;
            } else {                                                            // 有右子节点，右子节点入栈
                base[index].root = base[index - 1].root->right;
                base[index - 1].right = 1;
                index++;
            }
        } else {                                                                // 有左子节点，左子节点入栈
            base[index].root = base[index - 1].root->left;
            base[index - 1].left = 1;
            index++;
        }
    }
    return res;
}
```
