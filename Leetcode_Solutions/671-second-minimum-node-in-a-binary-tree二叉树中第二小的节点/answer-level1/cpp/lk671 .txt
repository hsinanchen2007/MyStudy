效率高，0秒 100%，
执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.4 MB
, 在所有 C++ 提交中击败了
92.31%
的用户
```
代码块/**
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
    unsigned int Min2 = INT_MAX + 100;
    void find(TreeNode* root) {
        if(root->left){
			if(root->left->val == root->val) find(root->left);
			else Min2 = min(Min2, (unsigned int)root->left->val);
		}
		if(root->right){
			if(root->right->val == root->val) find(root->right);
			else Min2 = min(Min2, (unsigned int)root->right->val);
		}
    }
    int findSecondMinimumValue(TreeNode* root) {
        find(root);
        if(Min2 == INT_MAX + 100) return -1;
		return Min2;
    }
};
```
