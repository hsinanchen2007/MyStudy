# *h*1. **






题解大神第四种动态规划解法的c++翻译版

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> pre;
        if(n==0)
            return pre;
        pre.push_back(NULL);
        for(int i = 1;i<=n;i++){
            vector<TreeNode*> cur;
            for(auto it : pre){
                TreeNode* insert = new TreeNode(i);
                insert->left = it;
                cur.push_back(insert);
                //插入右孩子
                for(int j = 0;j<n;j++){
                    TreeNode* root_copy = treeCopy(it);
                    TreeNode* right = root_copy;
                    int k = 0;
                    for(;k<j;k++){
                        if(right == NULL)
                            break;
                        right = right->right;
                    }
                    if(right == NULL)
                        break;
                    //保存当前右孩子的位置的子树作为插入节点的左孩子
                    TreeNode* rightTree = right->right;
                    insert = new TreeNode(i);
                    right->right = insert; //右孩子是插入的节点
                    insert->left = rightTree; //插入节点的左孩子更新为插入位置之前的子树
                    cur.push_back(root_copy);

                }
            }
            pre = cur;
        }
        return pre;
    }
    TreeNode* treeCopy(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = treeCopy(root->left);
        newRoot->right = treeCopy(root->right);
        return newRoot;

    }
};
```