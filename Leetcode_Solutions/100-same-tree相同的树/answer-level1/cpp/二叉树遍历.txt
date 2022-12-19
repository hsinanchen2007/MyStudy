### 解题思路
此处撰写解题思路
就是二叉树的遍历嘛.
通过对二叉树递归式遍历的变形即可.
当然也可以通过分层遍历进而对比也行.
不过这样就得维护两个队列.
这不会发生溢出,效率也跟递归差不多.
当然代码复杂度要高点.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&q) return false;
        else if(p&&!q) return false;
        else if(!p&&!q) return true;
        else
        {
            if(p->val!=q->val) return false;
            else
            {
                bool flag=isSameTree(p->left,q->left);
                flag=flag&&isSameTree(p->right,q->right);
                return flag;
            }
        }
    }
};
```