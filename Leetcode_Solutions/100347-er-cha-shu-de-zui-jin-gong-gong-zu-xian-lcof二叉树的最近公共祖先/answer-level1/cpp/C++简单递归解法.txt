### 解题思路
本来一开始是法二的写法，想着找到了就不再继续遍历，节省时间，结果发现好像两种方法差别好像不大?!
本着简洁风格，还是换成了法一的写法（好看最重要）

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
    //法一
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;                //若当前为空或者匹配，则返回自身
        TreeNode* left = lowestCommonAncestor(root->left, p, q);          //左子树
        TreeNode* right = lowestCommonAncestor(root->right, p, q);      //右子树
        if(!left) return right;                                         
        if(!right) return left;
        return root;                 //左右均匹配到，则答案为当前root
    }                                //之后其他子树不可能再匹配到，所以结果必然是当前root

    //法二
    // TreeNode* ans;
    // int findNode(TreeNode* root, TreeNode* p, TreeNode* q)
    // {
    //     if(!root) return 0;
    //     int left = findNode(root->left, p, q);
    //     if(left==2) return 2;                   //左边找到两个则不用继续
    //     int right = findNode(root->right, p, q);
    //     if(right==2) return 2;                  //右边找到两个则不用继续
    //     int num = left + right + ( root==p || root == q ? 1 : 0);   //左右加当前节点找到的个数
    //     if(num==2) ans = root;                                      //当前子树找到则答案为root
    //     return num;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     findNode(root,p,q);
    //     return ans;
    // }
};
```