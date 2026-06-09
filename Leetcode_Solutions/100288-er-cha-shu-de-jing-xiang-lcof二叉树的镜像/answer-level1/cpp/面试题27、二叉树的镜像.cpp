### 解题思路1：递归
思路1、本质还是遍历树，因此没有特殊要求，递归是最简洁的代码。
递归的时候想清楚：
1. 递归终止的条件（到叶节点NULL）；
2. 递归的返回值以及先操作再递归还是先递归，然后到达叶节点开始操作；
    本题中，因为交换节点指向直接就把该节点下的书都移过去了，所以先递归再操作即可。显然不需要返回值，交换完了，最后把根节点返回就行。

### C++代码

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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode* tmp = root->left;
        root ->left = root->right;
        root->right = tmp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
```
### 解题思路2：用队列来存储
思路2：队列存储。
1. 先把跟节点入队；
2. 循环条件，队列不为空；
3. 取出队头，若不为空节点，则`swap（left，right）`，为空则continue；
4. 然后队头的左右节点入队，循环；
5. 返回根节点。
### C++代码

```
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if(tmp == NULL)
                continue;
            swap(tmp->left,tmp->right);
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return root;
    }
};
```
