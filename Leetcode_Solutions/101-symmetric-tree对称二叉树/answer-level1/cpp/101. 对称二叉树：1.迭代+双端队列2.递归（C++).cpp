### 解题思路
* 镜像对称条件：
* 1、A与A'根节点值相等；
* 2、A的左子树与A'的右子树对称，A的右子树与A'的左子树对称。

### 代码
* 递归
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
    bool isSymmetric(TreeNode* root) {
        // if(!root)   return true;    // 空返回真
        // if(root->left == NULL && root->right == NULL)   return true;    // 只有根节点返回真

        return isMirror(root, root);
    }
    bool isMirror(TreeNode *l, TreeNode *r) {
        if(l == NULL && r == NULL)  return true;
        if(l == NULL || r == NULL)  return false;
        return (l->val == r->val && 
                isMirror(l->left, r->right) && isMirror(l->right, r->left));
    }
};
```
![递归.png](https://pic.leetcode-cn.com/7c980e17597e7abe0f82eaa2d2eab59d4c4060d3fd3e3278db89aa6fe5c2a2e0-%E9%80%92%E5%BD%92.png)
* 迭代+双端队列
```cpp
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;    // 空返回真
        if(root->left == NULL && root->right == NULL)   return true;    // 只有根节点返回真
        // 不好处理只有根节点的情况，因此从第二层开始处理
        deque<TreeNode*> dq;
        dq.push_back(root->right);
        dq.push_front(root->left);
        while(!dq.empty()) {
            TreeNode *tl = dq.front();
            TreeNode *tr = dq.back();
            if(tl == NULL && tr == NULL) {
                dq.pop_front();
                dq.pop_back();
            }
            else if(tl == NULL || tr == NULL)
                return false;
            else if(tl->val != tr->val)
                return false;
            else {
                dq.pop_front();
                dq.pop_back();

                dq.push_front(tl->right);   // 注意放入双端队列顺序
                dq.push_front(tl->left);
                dq.push_back(tr->left);
                dq.push_back(tr->right);
            }
        }
        return true;
    }
```
![deque.png](https://pic.leetcode-cn.com/6be1aec305ebb2dc95061dc16c6ff56b67fb1fe17cb7fa7a1d7a45bf701a80b7-deque.png)
