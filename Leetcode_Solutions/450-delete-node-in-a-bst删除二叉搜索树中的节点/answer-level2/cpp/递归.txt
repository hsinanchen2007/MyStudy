### 解题思路
递归(其实和迭代差不多)

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val < key) root->right = deleteNode(root->right,key);//递归直到找到删除节点
        else if(root->val > key) root->left = deleteNode(root->left,key);
        else{                                       // 这里是root值等于key时情况
            if(root->left==NULL || root->right==NULL) //root的左树或有树为空时
                return root->left==NULL ? root->right:root->left;//均为空返回空
                                                                //否则返回非空的子树
            if(root->left->right==NULL){               // 这里是可以直接将左子树提升的情况
                root->left->right = root->right;        // 左子树的根节点无右节点时
                return root->left;
            }
            int &c = root->val;                         // 以下是不能直接提升的情况
            TreeNode* p = root;                         // 通过改变需要删除节点的值
            p=p->left;                                  
            while(p->right->right!=NULL){               // 找到需删除节点的右子树中最大值
                p=p->right;                             // 需要保留倒数第二个节点
            }
            c = p->right->val;                          // 改值
            if(p->right->left==NULL)                    // 最大值为叶子时
                p->right =NULL;
            else                                        // 最大值的节点存在左节点
                p->right = p->right->left;
        }
        return root;
    }
};
```