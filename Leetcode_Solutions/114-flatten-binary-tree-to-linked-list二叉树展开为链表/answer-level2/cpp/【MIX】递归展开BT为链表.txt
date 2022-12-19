### 解题思路
可以使用PreOrder

### 代码

```java []
class Solution {
    private TreeNode pre = null;
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        flatten(root.right);
        flatten(root.left);
        root.right = pre;
        root.left = null;
        pre = root;
    }
}
```
```python []
class Solution:
    def __init__(self):
        self.lastNode = None

    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return

        if self.lastNode != None:
            self.lastNode.left = None
            self.lastNode.right = root;

        self.lastNode = root
        right = root.right
        self.flatten(root.left)
        self.flatten(right)
```
```c++ []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        // 递归实现
        if(root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);
        // 连接链表
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }

private:
    TreeNode *pre = nullptr;
};
```
