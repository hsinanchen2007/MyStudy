### 解题思路
此处撰写解题思路
递归求解思路：postorder数组中依次作为子树的根节点，在处理每个根节点时，inorder数组中找到该根节点所在的位置，即
i = FindIndex(inorder, left, right, node->val);
以i为界，将inorder数组分为左右两部分（有可能为空），分别是当前根节点的左右子树。
递归上述过程即可求解。
注意点：
1）后续遍历的顺序是：左子树 --> 右子树 --> 根节点，因此递归函数中处理时应该反过来，即 根节点 --> 右子树 --> 左子树
2）注意递归结束的条件有两个，第一个是postorder的索引，这是为了防止数组越界访问，第二个是inorder数组的左右边界 left >= right，这是为了处理叶子节点的场景。

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
int FindIndex(int *array, int left, int right, int val)
{
    while (left <= right) {
        if (array[left] == val) {
            return left;
        }
        left++;
    }

    return -1;
}
struct TreeNode *SubTree(int *inorder, int left, int right, int *postorder, int *index)
{
    struct TreeNode *node = NULL;
    int i;

    if (*index < 0 || left > right) {
        return NULL;
    }
    //printf("left=%d, right=%d, index=%d, value=%d\n", left, right, *index, postorder[*index]);

    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset(node, 0, sizeof(struct TreeNode));
    node->val = postorder[*index];
    //printf("node->val = %d, i = %d\n", node->val, i);
    (*index)--;

    i = FindIndex(inorder, left, right, node->val);
    if (i == -1) {
        return node;
    }

    node->right = SubTree(inorder, i + 1, right, postorder, index);
    node->left = SubTree(inorder, left, i - 1, postorder, index);

    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int index = postorderSize - 1;

    return SubTree(inorder, 0, inorderSize - 1, postorder, &index);
}
```