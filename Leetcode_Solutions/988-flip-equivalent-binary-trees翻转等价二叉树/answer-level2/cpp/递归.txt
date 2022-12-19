### 解题思路
首先判断两个节点的左孩子节点值是否相等，如果相等递归比较两个节点的左子树和右子树；如果不等则交换比较两个节点的左子树和右子树。
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
    bool ans = true;  //初始化为true
    bool isDeng(TreeNode* root1, TreeNode* root2)  //比较两个节点的值是否相等
    {
        if(root1 == NULL && root2 == NULL) return true;
        else if(root1 && root2 && root1 -> val == root2 -> val) return true;
        return false;
    }
    void isEquiv(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL) return ;
        else if(root1 && root2) 
        {
            if(isDeng(root1 -> left, root2 -> left))  //如果左子树的值相等，递归比较左右子树
              {
                  isEquiv(root1 -> left, root2 -> left);
                  isEquiv(root1 -> right, root2 -> right);
              }
            else if(isDeng(root1 ->right, root2 -> left))  //如果一个节点的左子树与另一个节点的右子树相等，交换递归比较
            {
                isEquiv(root1 -> left, root2 -> right);
                isEquiv(root1 -> right, root2 -> left);
            }
            else  //如果以上两种情况都不符合，则结果为false
            {
                ans = false;
                return ;
            }
        }
        else  //如果一个节点为空，另一个不为空，结果为false
        {
            ans = false;
            return ;
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 != NULL && root2 != NULL)  //比较两棵树的根节点的值
        {
            if(root1 -> val != root2 -> val) return false;
            else isEquiv(root1, root2);
        }
        else if(root1 == NULL && root2 == NULL) return true;
        else ans = false;
        return ans;
    }
};