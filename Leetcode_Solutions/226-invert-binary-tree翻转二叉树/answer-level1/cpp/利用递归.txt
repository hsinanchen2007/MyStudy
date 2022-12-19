首先我们判断递归条件，一个树要翻转成功需要子树已经翻转成功，那么肯定要用到递归，递归成功的条件就是是否一个子树已经完成翻转，即树左节点与右节点进行交换。
在递归算法的编写过程中，最烦的就是边界条件以及NULL节点的处理，在下面代码中，我们分别判断树根节点是否有左右子节点，如果没有那么直接跳出，如果有，那么继续进行交换。
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;
    }
private:
    void reverse(TreeNode* lnode){
        if(!lnode){
            return;
        }
        if(lnode->left){
        TreeNode* temp = lnode->left;
        lnode->left = lnode->right;
        lnode->right = temp;
        }else{
        TreeNode*temp = lnode->right;
        lnode->right = lnode->left;
        lnode->left = temp;
        }
        reverse(lnode->left);

        reverse(lnode->right);
  }
};
```
