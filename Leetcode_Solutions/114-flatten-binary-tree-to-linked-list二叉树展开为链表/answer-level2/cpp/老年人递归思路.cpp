![QQ图片20200321104935.png](https://pic.leetcode-cn.com/83157cfa4ee97b08f39bf485ec4c1c9c4612785d2906e17e3fffb7c36cfb5d61-QQ%E5%9B%BE%E7%89%8720200321104935.png)

+ 先递归将每一颗子树均整合成只有右子树的形式
+ 再将右子树插入左子树的末尾节点，将左子树插入root的右子树部分
+ 将root的左子树置为空，再返回root

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
    void flatten(TreeNode* root) {
        root = build(root);
    }

    TreeNode*build(TreeNode*root)
    {
        
        if(!root||root->right==NULL&&root->left==NULL)//叶子节点，空节点直接返回
            return root;
        //先序遍历建立链表
        root->left = build(root->left);
        root->right = build(root->right);
        //找到左子树的最右端;
        TreeNode*p = root->left;
        if(p)
        {
            while(p->right!=NULL)
                p=p->right;
            p->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
        return root;
    }
};
```