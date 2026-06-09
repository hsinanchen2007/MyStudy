### 解题思路

由 1 ... n 为节点所组成的二叉搜索树
依次以 k 为根节点 (1<=k<=n) 建立二叉搜索树
它的左子树的结点在 [1,k-1] ，右子树的结点在 [k+1,n]
根节点的左孩子在 [1,k-1] 中依次取，设为 t
则结点 t 的左子树在 [1,t-1] , 右子树在 [t+1,k-1]

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
    vector<TreeNode*> dfs(int l,int r){
        vector<TreeNode*> res;
        if(l > r){
            res.push_back(NULL);
            return res;
        }
        for(int i = l;i <= r;i ++){       //以i为根节点
            auto left = dfs(l,i - 1);     //以i为根节点的左子树所有的可能情况
            auto right = dfs(i + 1,r);    //以i为根节点的右子树所有的可能情况
            for(auto &lt : left)          //在左子树所有情况和右子树所有情况中各取一种
               for(auto &rt : right){
                   TreeNode* root = new TreeNode(i);
                   root->left = lt;
                   root->right = rt;
                   res.push_back(root);
               }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return dfs(1,n);
    }
};
```