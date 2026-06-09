```
class Solution {
private:
    int record = 0;
    TreeNode* result;
  
    void postorder(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)return;
        int temp = record; //记录此时遍历这个结点的孩子之前已经遇到了多少次p或q
        postorder(root->left,p,q);
        postorder(root->right,p,q);
        if(root == q || root == p){
            record++;
        }
        if(record == 2 && temp == 0){
            result = root;
            record++; //因为是最近的祖先，所以第一次遇到满足祖先的值，就要把record+1，让后面的祖先
                        //对该if语句判断失败。
        }
            
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        postorder(root,p,q);
        return result;
    }
};
```
没有用到二叉搜索树的性质，而是利用先访问结点的儿子再访问自己后序遍历的特点来解决。