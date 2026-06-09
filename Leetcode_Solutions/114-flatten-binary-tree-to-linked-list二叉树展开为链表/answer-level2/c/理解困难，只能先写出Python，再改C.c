Python代码：按照牛人的思路，反向前序遍历。
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.temp = None

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.nodeIter(root)

    def nodeIter(self, root: TreeNode) -> None:
        if root:
            self.nodeIter(root.right)
            self.nodeIter(root.left)
            root.right = self.temp
            root.left = None
            self.temp = root

```


C代码：照着改，声明空变量有区别，要先声明指针，再开辟空间，再初始化。
直接声明NULL的话，NULL没有地址，传递不了。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void nodeIter(struct TreeNode*, struct TreeNode**);

void flatten(struct TreeNode* root){
    struct TreeNode** temp = (struct TreeNode**)calloc(1, sizeof(struct TreeNode*));
    nodeIter(root, temp);
}

void nodeIter(struct TreeNode* root, struct TreeNode** temp){
    if (root){
        nodeIter(root->right, temp);
        nodeIter(root->left, temp);
        root->right = *temp;
        root->left = NULL;
        *temp = root;
    }
}
```
