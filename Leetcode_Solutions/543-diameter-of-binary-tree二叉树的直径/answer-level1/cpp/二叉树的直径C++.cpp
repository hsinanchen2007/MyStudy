## depth返回以no为根的子树的深度，有些人可能觉得，那直接在子函数里返回L+R，但这只是求了经过根节点的最长路径，实际上，最长直径不一定过根节点，必须比较所有内部节点的经过的最长直径。
## 所以才会在子函数里在求树的深度的同时不断更新最长直径

```
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
    int ans;
    int depth(TreeNode* no){//返回以no为根的子树深度
        if(no==NULL) return 0;
        int L=depth(no->left); //左儿子为根的子树的深度
        int R=depth(no->right);
        ans=max(ans,L+R+1); //更新ans：最大直径
        return max(R,L)+1;
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;//初始化当空树的时候，结果为0
        depth(root);
        return ans-1;
    }
};
```