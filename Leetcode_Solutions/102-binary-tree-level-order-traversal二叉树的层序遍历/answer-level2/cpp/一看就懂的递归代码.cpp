### 解题思路
![2.png](https://pic.leetcode-cn.com/b83ac08cb8f462b12539df3832d2abdc866b6fbddf0826613d3325cbbfe4a2a3-2.png)

先用递归求出二叉树的层数。
然后通过节点和层级来进行递归将答案写进容器中。
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
    vector<vector<int>>ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        int n=howlen(root);
        ans.resize(n);
        levelOrder(root,0);
        return ans;
    }
    void levelOrder(TreeNode* root,int n){//n为此时节点所在的层，根节点为第零层，每次递归都加1
        ans[n].push_back(root->val);
        if(root->left) levelOrder(root->left,n+1);
        if(root->right) levelOrder(root->right,n+1);
    }
    int howlen(TreeNode* root){//用递归求树的总层数
        if(root==NULL) return 0;
        return max(howlen(root->left),howlen(root->right))+1;
    }
};
```