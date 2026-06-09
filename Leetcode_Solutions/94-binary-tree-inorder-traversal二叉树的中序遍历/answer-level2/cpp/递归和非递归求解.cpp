### 解题思路
解法1
```
    复杂度分析：
        时间复杂度：O(n)O(n)。递归函数T(n)=2⋅T(n/2)+1。
        空间复杂度：最坏情况下需要空间O(n)，平均情况为O(log n)。
``` 

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
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};
```

解法2

```
    复杂度分析：
        时间复杂度：O(n)。
        空间复杂：O(n)。
``` 


```cpp
class Solution {
public:
    vector<int>res;
    stack<TreeNode*>s;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root, *top;
        while(!s.empty() || curr) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            if(!s.empty()) {
                top = s.top();
                s.pop();
            }
            res.push_back(top->val);
            curr = top->right;
        }
        return res;
    }
};
```
解法3 莫里斯遍历
```
Step 1: 将当前节点current初始化为根节点

Step 2: While current不为空，

若current没有左子节点

    a. 将current添加到输出

    b. 进入右子树，亦即, current = current.right

否则

    a. 在current的左子树中，令current成为最右侧节点的右子节点

    b. 进入左子树，亦即，current = current.left
```

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       TreeNode* curr = root, *pre;
       while(curr) {
           if(!curr->left) {
               ans.push_back(curr->val);
               curr = curr->right; 
           }
           else {
               pre = curr->left;
               while(pre->right) {
                   pre = pre->right;
               }
               pre->right = curr;
               TreeNode* tmp = curr;
               curr = curr->left;
               tmp->left = nullptr;
           }
       }
       return ans;
    }
};
```