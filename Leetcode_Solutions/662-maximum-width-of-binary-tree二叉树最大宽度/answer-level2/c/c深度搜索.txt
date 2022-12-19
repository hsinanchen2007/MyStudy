### 解题思路
用了官方的深度搜索的思路，c要注意pos可能会超过int的最大长度。这里用了double

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
 int max = 1;
void func(struct TreeNode *node, int index, double pos, int *a) {
    
    if (node == NULL) {
        return;
    }
    if (a[index] == 0) {
        a[index] = pos;
    } else {
        max = max > (pos - a[index] + 1) ? max : (pos - a[index] + 1);
    }
    func(node->left, index + 1, 2 * pos, a);
    func(node->right, index + 1, 2 * pos + 1, a);
}

int widthOfBinaryTree(struct TreeNode* root){
    int index = 0;
    int a[1000000] = {0};

    if (root == NULL) {
        return 0;
    }
    max = 1;
    func(root, 1, 1, a);
    return max;
}


```