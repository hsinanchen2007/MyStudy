
![7.png](https://pic.leetcode-cn.com/1d3670f0f24723aa9d97fc1aea600d8568157e7fd60091a084bcf81f8432fd78-7.png)

典型的分治法思路，创建的节点为前序遍历区间 第一个数（前序顺序为根左右），然后通过中序遍历序列找到该节点，算出偏移值，
这个偏移值用来确定当前节点左子树所在的区间和右子数所在的区间。
如图所示：偏移值step=4,怎么算出来？就是找到inorder中第几个数等于preorder[i]
偏移值确定后，左子树和柚子树的区间就定下来了，具体关系看代码。会发现又是一个子问题，所以用分治法。
```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        helper(&root,0,preorder.size()-1,preorder,0,inorder.size()-1,inorder);
        return root;
    }
    /**/
    TreeNode* helper(TreeNode**root, int i,int j,vector<int>& preorder, int x,int y,vector<int>& inorder){
        if(j<i) return NULL;
        if(y<x) return NULL;
        *root = new TreeNode(preorder[i]);

        int step = 0;
        for(int k=x;k<y;k++){
            if(preorder[i] == inorder[k]){
                break;
            }
            step++;
        }
        //cout<<step<<endl;
        TreeNode* left = helper(&(*root)->left,i+1,i+step,preorder,x,x+step-1,inorder);
        TreeNode* right = helper(&(*root)->right,i+step+1,j,preorder,x+step+1,y,inorder);
        (*root)->left = left;
        (*root)->right = right;
        return *root;
    }
};
```
