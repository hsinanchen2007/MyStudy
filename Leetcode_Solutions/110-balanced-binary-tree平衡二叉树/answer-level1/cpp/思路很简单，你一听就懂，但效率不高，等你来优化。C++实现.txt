### 解题思路
判断一棵二叉树是否为平衡二叉树，很容易想到的一个思路就是：
step1：如果树为空，那么根据平衡二叉树的定义我们知道，空树是平衡二叉树。否则，执行step2。
step2：如果树不空，我们判断这棵树的左子树和右子树是否为平衡二叉树，如果左右子树至少一个不为平衡二叉树，那么整棵树必然不是平衡二叉树。否则执行step3。
step3：判断左右子树的高度差的绝对值是否不超过1，若是则整棵树为平衡二叉树，否则，不为平衡二叉树。

下面是C++实现的代码:
### 代码

```cpp
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            //空树是平衡二叉树
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) &&
        abs(height(root->left)-height(root->right)) <= 1;
    }
    int height(TreeNode *t){
        if (t == NULL){
            return 0;
        }
        else {
            int lchild = height(t->left);
            int rchild = height(t->right);
            return lchild > rchild ? lchild + 1 : rchild + 1;
        }
    }
};
```

不难看出，对于整棵树，我们对所有节点都访问了两次，第一次判断左右子树是否平衡，第二次计算高度，显然这是不必要的。那么，能否通过遍历一遍就把这两件事干完呢？答案是可以的！你自己想呗