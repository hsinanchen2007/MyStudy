#### 模型
二叉树的后序遍历

#### 为什么是后序遍历
二叉树的遍历无非就先序，中序和后序三种。其中只有后序遍历才是遍历完所有子结点之后才遍历根结点，这也正符合题目中的描述：
> 一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

所以需要使用后序遍历操作删除子树的所有值为`target`的子结点，再判断根结点。

#### 代码：

```cpp
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) {
            return NULL;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == NULL && root->right == NULL && root->val == target) {
            return NULL;
        }
        return root;
    }
};
```
#### 为什么使用带返回值的递归函数
二叉树的删除结点操作和链表的删除结点操作本质并无差别，在链表中如果要删除一个结点`node`我们需要知道`node`的先序结点，在二叉树中也是如此。

在这道题中要删除值为`target`的叶子节点，如果不使用带返回值的递归函数，那就需要在遍历到他的父结点`parent`的时候将`parent->left(或right) = NULL`，这会增加许多繁琐的逻辑判断操作。

使用带返回值的递归函数，我们就可以直接将符合条件的当前叶子节点直接以`NULL`的形式，返回给它父结点的相应子树：`parent->left(或right)`，而不需要在父结点中进行删除操作，从而简化了逻辑判断。

- - -

欢迎大家留言讨论交流！
