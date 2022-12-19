### 解题思路
这题的第一个问题是要看懂题目
我刚开始就看花咯。。
2-1这个边才是一个长度
那我们当然是求最大长度第一想法就是根节点啊
那肯定是最长的啊left -> root -> right这样 因为根能到达任意嘛
这样的想法其实是正确的，但是有一个条件那就是最优的情况下
还有一种情况它不一定是最优的
那就是

          1
         / \
        2   3
       / \     
      4    5  
         /   \   
        6     7 
       / \   / \    
      8   9 10  11
     / \       /  \  
    12 13     14  15
   / \            / \  
  16  17         18  19

在这里1为根节点 左边最深的 + 右边最深的 = 7
但是 如果以 5 为根节点 那么左边最深是4 + 右边最深的 = 8
这样看其实不一定是root是最大的 
我们就要每一次都判断left + right 的值 然后我们取一个最大的就是解啦

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
    int max = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int left = dfs(root->left);
        int right = dfs(root->right);
        int value =  left + right;
        max = max > value ? max : value;
        return max;
    }

    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        int value =  left + right;
        max = max > value ? max : value;
        return (left > right ? left : right) + 1;
    }
};
```