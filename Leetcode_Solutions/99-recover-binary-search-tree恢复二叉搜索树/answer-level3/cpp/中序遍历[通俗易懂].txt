# 中序遍历[通俗易懂]
本方法不是最方便的，也不是效率最高的，但是却是最好懂的。
分3步：
1、inOrder函数，递归求出当前二叉树的中序遍历；
2、sort排序，由小到大；
3、recover重建二叉树：这里再次利用inOrder去遍历获取原来的儿茶素，并和当前已经sort过的vector元素作比较，如果相等，就直接erase(vec.bein())，
如果不相等，那么就把sort过后的值赋予当前节点既可。

原理是：**二叉搜索树的中序遍历一定是单调递增的，所以sort完之后一定就是对应的正确的结果，那么再对错误的二叉树中序遍历，逐个比对修改就好。**

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
    void recoverTree(TreeNode* root) {
        vector<int> result;
        inOrder(root,result);
        sort(result.begin(),result.end());
        recover(root,result);
    }

    void inOrder(TreeNode* root,vector<int>& vecResult){
        if(root == nullptr){
            return;
        }
        inOrder(root->left,vecResult);
        vecResult.push_back(root->val);
        inOrder(root->right,vecResult);
    }

    void recover(TreeNode* root,vector<int>& rec){
        if(root ==nullptr){
            return;
        }
        recover(root->left,rec);
        if(root->val == rec[0]){
            rec.erase(rec.begin());
        }else{
            root->val = rec[0];
            rec.erase(rec.begin());
        };
        recover(root->right,rec);
    }
};
```
