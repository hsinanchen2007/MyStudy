### 解题思路
本题我最开始的思路是，用递归遍历每一个节点，检验每一个节点是否满足 左值大于中值大于右值。但是这个有些节点尽管满足这个，但是现实生活中是不可能把BST插入成这样的，它的inorder顺序的数字不是递增的。
于是我的思路改成检验inorder递增。
第二次出错是因为节点相等时出错。
第三次出错时因为没考虑到大的负整数。
第四次出错是因为没考虑到int型最大的负数。
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
    vector<int> nodes;
    void inorder(TreeNode* root){
        if(root->left){
            inorder(root->left);
        }
        nodes.push_back(root->val);
        if(root->right){
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        inorder(root);
        int temp=nodes[0];
        for(vector<int>::iterator it=nodes.begin()+1;it!=nodes.end();it++){
            if(temp>=*it){
                return false;
            }
            temp=*it;
        }
        return true;
    }
};
```