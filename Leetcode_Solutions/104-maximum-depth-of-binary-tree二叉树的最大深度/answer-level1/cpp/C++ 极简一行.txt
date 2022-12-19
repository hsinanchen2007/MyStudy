执行用时 :16 ms, 在所有 C++ 提交中击败了65.81%的用户
内存消耗 :19.5 MB, 在所有 C++ 提交中击败了31.92%的用户
```
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};
```
实际上，最简不太好理解的话看一下这个简洁版本：
```
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root){
            return 0;
        }
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```

