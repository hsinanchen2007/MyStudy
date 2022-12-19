### 解题思路
这里定义一个depth，每向下一层深度加1，采取的先序遍历，找到叶子节点，就相互比较，如果小于的话，那么更新，否则不更新。
ans = min(ans,depth)。 这里的思路是从上往下走，大白话就是递归是递进和回归两步走，这里是在递进过程中。
另外一种方法，自底向上回溯过程，解决问题。
猜测，用BFS也可以。

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
    int minDepth(TreeNode* root) {
        // 返回root到叶子节点的最短距离
        if(!root) return 0;
        else{
            int ans=0x3f3f3f3f;
           getMinDepth(root,1,ans);
           return ans;
        }
    }
    void getMinDepth(TreeNode* root,int depth,int &ans){
        if(!root->left&&!root->right){
            ans=min(ans,depth);
            return;
        }
        if(root->left)  getMinDepth(root->left,depth+1,ans);
        if(root->right) getMinDepth(root->right,depth+1,ans);
        return;
    }
};
```