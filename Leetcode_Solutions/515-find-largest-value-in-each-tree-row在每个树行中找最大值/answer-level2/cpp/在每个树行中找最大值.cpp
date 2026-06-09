### 解题思路
声明一个height的形参，用来记录该节点的高度，再和res.size()比，如果res.size()<height说明res没有该高度的值，此时res需要直接加进去，如果res.size()>height，说明该位置的值已经有了，此时需要res[height-1]和该节点的值比大小。（res[height-1]指在以遍历的高度为height的结点上的最大值）

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
    vector<int>res;
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return res;
        helper(root,1);
        return res;
    }
    void helper(TreeNode *root,int height){
        if(root==NULL) return ;  //终止条件
        if(height>res.size()) res.push_back(root->val); //裂开，我写的是res.push_bacK(height),我说吗肯定对，但是就是有问题，终于找到了 -o-'
        else if(root->val>res[height-1]) res[height-1]=root->val; //在该节点需要做什么。。在得到怎么进行递归。。（使用哪种遍历方式。）
        helper(root->left,height+1);
        helper(root->right,height+1);
    }
};
```