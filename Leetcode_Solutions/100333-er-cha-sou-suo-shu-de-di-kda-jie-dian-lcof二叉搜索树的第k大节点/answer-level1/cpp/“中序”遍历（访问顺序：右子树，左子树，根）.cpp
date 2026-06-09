### 解题思路
中序遍历得到值递增，因此修改插入栈中的顺序，先右子树，后左子树，再访问根，即可得到值递减。

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
    int kthLargest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        vector<int> vec;
        stack<TreeNode*> sta;
        TreeNode* cur;
        cur=root;
        while(!sta.empty()||cur!=NULL){
            while(cur!=NULL)
              {
                  sta.push(cur);
                  cur=cur->right;
              }
              cur=sta.top();
              sta.pop();
              vec.push_back(cur->val);
              cur=cur->left;
        }
        return vec[k-1];
    }
};
```