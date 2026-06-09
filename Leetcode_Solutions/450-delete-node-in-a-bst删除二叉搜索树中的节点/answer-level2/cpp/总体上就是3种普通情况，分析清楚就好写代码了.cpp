首先是找要删除的结点，因为是二叉搜索树，所以直接分左右支找到就行。
然后是根绝要删除结点的子结点情况，分为以下3种情况（代码delete部分对应的）：
*维持一个指向删除节点父节点的指针(pre)
1、删除的结点无左右子节点，那么直接将其父节点指向NULL；
2、删除的结点只有1个子节点，分左右两种情况，直接将其父节点指向删除节点的子节点；
3、删除节点有2个子节点，这是最麻烦的情况了，最好是画个图理解，具体而言：
假设删除节点为A，其左子节点为B，右子节点为C；B的左右子节点分为D、E。C的左右子节点为F、G。
我选择__总是将删除节点的 _右子节点_ 提升到删除节点的位置__。
在这种情况下，即将C提升至A的位置，让B节点（及其所有子节点）成为C的左子树；至于C的右子树G则不变；
那么C原本的左子树F必须移动到新的位置（因为B节点已经成为了C节点新的左子树），根据二叉树的特性，
树F的元素均大于B树的元素，因此将F树移动到B树的最右下位置。

在考虑了所有情况后，还要注意如果删除的节点恰好是根结点的情况。
```
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        //search node
        auto cur=root;
        auto pre=root;
        while(cur&&cur->val!=key){
            pre=cur;
            if(cur->val>key)
                cur=cur->left;
            else 
                cur=cur->right;
        }
        //dont find
        if(!cur)
            return root;
        //delete
        if(!cur->left&&!cur->right){
            if(cur==root)
                return NULL;
            if(pre->left==cur)
                pre->left=NULL;
            else
                pre->right=NULL;
        }else if(cur->left&&!cur->right){
            if(cur==root)
                return cur->left;
            if(pre->left==cur)
                pre->left=cur->left;
            else
                pre->right=cur->left;
        }else if(cur->right&&!cur->left){
            if(cur==root)
                return cur->right;
            if(pre->left==cur)
                pre->left=cur->right;
            else
                pre->right=cur->right;
        }else{
            auto b=cur->left;
            while(b->right)
                b=b->right;

            b->right=cur->right->left;
           
            cur->right->left=cur->left;
            if(cur==root)
                return cur->right;
            if(pre->left==cur)
                pre->left=cur->right;
            else
                pre->right=cur->right;
        }
        
        return root;    
    }
};
```

执行用时 : 32 ms, 在Delete Node in a BST的C++提交中击败了100.00% 的用户

内存消耗 : 12.7 MB, 在Delete Node in a BST的C++提交中击败了79.49% 的用户
