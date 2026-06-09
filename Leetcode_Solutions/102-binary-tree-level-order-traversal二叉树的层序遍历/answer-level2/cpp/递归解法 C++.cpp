用的递归写法，，用一个变量level来标记当前的深度，一开始带入0，代表根节点所在的深度。因为返回的是一个二维数组res，一开始我们不知道而二叉树的深度，不知道有多少层，因此我们无法事先申请好二维数组的大小，只有在遍历的过程中增加层的大小。

那什么时候应该申请新的一层？ 当level等于当前二维数组的大小的时候。为啥是等于呢，不是说要超过当前的深度么，这是因为level是从0开始的，就好比一个长度为n的数组A，你访问A[n]是会出错的，当level等于数组的长度时，就已经需要新申请一层了，我们新建一个空层，继续往里面加数字，AC代码如下：


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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,0,res);
        return res;
    }
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) 
    {
        if(!node) return ;
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left,level+1, res);
        if(node->right) levelorder(node->right,level+1,res);
    }
};
```
