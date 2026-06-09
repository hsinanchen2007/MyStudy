### 解题思路
主要的思想是分治的思想，利用递归的方法，从根节点开始，左子树右子树依次看过去是否满足条件
方法1是利用题104利用求二叉树的最大深度 为 求深度函数，之后递归地判断每个节点是否满足
方法2是将求深度与判断是否平衡放在一起递归，同样也是分治的思想，求解时间上会更优

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
    bool isBalanced(TreeNode* root){
        if(root == NULL)return true;
        if(abs(maxDepth(root -> left)-maxDepth(root -> right))>1)return false;
        if(!isBalanced(root -> left))return false;
        if(!isBalanced(root -> right))return false;
        return true;
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root -> left)+1 , maxDepth(root -> right) +1);
    }
};

 /*
 //返回值的结构体
 typedef struct _resulttype{
     int depth= 0;
     int isBalanced = false;
 } ResultType;

class Solution {
public:
    ResultType helper(TreeNode* root){
        ResultType rt = ResultType();
        if(root == NULL){
            rt.isBalanced = true;
            return rt;
        }
        ResultType left = helper(root -> left);
        ResultType right = helper(root -> right);
        if(!left.isBalanced || !right.isBalanced || abs(left.depth-right.depth)>1){
            rt.isBalanced = false;
            //return rt;
        }
        else {
            rt.depth = max(left.depth,right.depth) + 1;
            rt.isBalanced = true;
        }
        return rt;
    }
    bool isBalanced(TreeNode* root){
            return helper(root).isBalanced;
    }
};*/
```