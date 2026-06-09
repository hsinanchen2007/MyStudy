### 解题思路
1.类似于层序遍历二叉树。
2.先将root根结点加入队列两次，因为要做两个二叉树的对对比，第二个为二叉树的副本。
3.检查队列是否为空，将队首元素出队，进行对比，查看是否存在一个结点存在而另一个结点不存在，再查看两个结点都存在时两个结点的val值是否相同。
4.若上述都通过则表明二叉树遍历到此处时仍为对称，因此先入队原二叉树左节点和副本二叉树的右节点，再入队原二叉树的右节点和副本二叉树的左结点。
5.不断重复步骤3，步骤4。

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
    bool isSymmetric(TreeNode *root){
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
```