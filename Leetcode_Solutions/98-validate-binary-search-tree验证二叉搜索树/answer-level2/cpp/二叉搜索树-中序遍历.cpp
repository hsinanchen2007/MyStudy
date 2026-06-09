#题目描述
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

#题解
1，递归
2.迭代
3.中序遍历,inorder可以当做模板，如果中序遍历出来的结果是有序的 说明是二叉搜索树
考虑边界情况：（1）.两数相等，所以判断时要>=
（2）.输入的是一个空树，返回false

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
    void inorder(TreeNode* root, vector<int>& a){
        if(root==NULL) return;
        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    bool isValidBST(TreeNode* root) {
        if(root== NULL) return true;
        vector<int> a;
        inorder(root, a);
        for(int i=0; i<a.size()-1;i++){
            if(a[i]>=a[i+1]){
                return false;
            }
        }
        return true;
    }
};
```