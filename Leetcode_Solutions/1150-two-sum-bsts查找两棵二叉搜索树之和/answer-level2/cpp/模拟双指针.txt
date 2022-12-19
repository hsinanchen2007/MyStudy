![AG0)JK\]N`Y1()R62DF2AF8Y.png](https://pic.leetcode-cn.com/814d74410930284d55efe57b88551d6c8b08ab854b8d92718b73c1d43bf64a70-AG0\)JK%5DN%60Y1\(\)R62DF2AF8Y.png)
- 用两个栈分别对两棵树进行中序遍历，左边的树从小到大遍历，右边的树从大到小遍历。
```C++ []
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1==NULL || root2==NULL)
            return false;
        stack<TreeNode*> left,right;
        getLeft(root1,left);
        getRight(root2,right);
        TreeNode *l=left.top();//左指针
        left.pop();
        TreeNode *r=right.top();//右指针
        right.pop();
        while(true){
            int t=l->val+r->val;
            if(t==target)//找到
                return true;
            if(t>target){
                getRight(r->left,right);
                if(right.empty())
                    break;
                r=right.top();//右指针左移
                right.pop();
            }
            else if(t<target){
                getLeft(l->right,left);
                if(left.empty())
                    break;
                l=left.top();//左指针右移
                left.pop();
            }
        }
        return false;
    }
    
    void getLeft(TreeNode* root, stack<TreeNode*> &left){//将左边压入栈
        while(root){
            left.push(root);
            root=root->left;
        }
    }
    
    void getRight(TreeNode* root, stack<TreeNode*> &right){//将右边压入栈
        while(root){
            right.push(root);
            root=root->right;
        }
    }
};
```
