### 解题思路
题目要求找到最大的路径之和。
思路: 很快就写了出来，但是效率不是很好。
对于每个结点，返回经过我的可以被我的双亲采纳的最大值。
而目标结果最大值 通过一个全局变量来保存。

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
    int maxn=-0x3f3f3f3f;
public:
    int maxPathSum(TreeNode* root) {
        get_node(root);
        return maxn;
        
    }
    int get_node(TreeNode* root){
        if(!root) return 0;
        int left = get_node(root->left);
        int right = get_node(root->right);
        int maxn1 = max(root->val+left,root->val+right);
        int maxn2 = max(root->val,root->val+left+right);
        maxn = max(maxn,max(maxn1,maxn2));
        return max(root->val,maxn1);


    }

};
```