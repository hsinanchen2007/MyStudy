### 解题思路
其实就和二叉树展开的思路是一样的，用一个栈来按顺序遍历，然后计个数就好了。

用时8ms，击败100%用户

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
    stack<TreeNode*> numlist;
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        int num = 0;
        TreeNode* cur = root;
        numlist.push(root);
        while(num < k)
        {
            while(cur->left)
            {
                numlist.push(cur->left);
                cur = cur->left;
            }
            numlist.pop();
            num++;
            if(num == k)
                return cur->val;
            while(!cur->right)
            {
                cur = numlist.top();
                numlist.pop();
                num++;
                if(num == k)
                    return cur->val;
            }
            cur = cur->right;
            numlist.push(cur);
        }
        return 0;
    }
};
```