二叉搜索树的特点：
1.右子树节点值比父节点大
2.左子树节点值比父节点小
所以从右子树开始的中序遍历可以从大到小得到节点值
小技巧(自己有时候太蠢了，作为记录)：
1.给予k值，可以用k--直到0来确定结果，不需要再设定一个i++到k，浪费空间
2.想清楚哪些值需要引用，哪些需要传值
```
class Solution {
public:
    int res = 0;
    void inorder(TreeNode* root,int &k)
    {
        if(root!=NULL){
            inorder(root->right,k);
            k--;
            if(k==0){
                res = root->val;
            }
            else if(k>0)
                inorder(root->left,k);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
};
```
