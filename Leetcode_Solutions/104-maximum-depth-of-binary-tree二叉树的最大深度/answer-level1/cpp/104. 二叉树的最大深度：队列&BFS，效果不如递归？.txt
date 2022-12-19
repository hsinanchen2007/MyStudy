### 解题思路
* 层序遍历，利用queue存放TreeNode*类型，用top记录每层最后放入队列的元素，每次pop后如果跟top相等，则depth++。
* 耗时似乎比递归做法高。

### 代码1：队列&BFS

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;

        queue<TreeNode*> stk;
        stk.push(root);
        TreeNode *top = stk.back();
        int depth = 0;
        while(!stk.empty()) {
            TreeNode *tmp = stk.front();
            stk.pop();
            if(tmp->left)   stk.push(tmp->left);
            if(tmp->right)  stk.push(tmp->right);
            if(tmp == top) {
                depth++;
                top = stk.back();
            }
        }
        return depth;
    }
};
```
![2.png](https://pic.leetcode-cn.com/1337c3d9dab338f75dee56f74ae16682f4bad0d51a47ec2d134956b0162b040e-2.png)

### 代码2：递归
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)    return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};
```
![1.png](https://pic.leetcode-cn.com/47f31b46299a9a50fc506c8057cd9c207fef35106cf77ca8fff984dbe1d9de06-1.png)

