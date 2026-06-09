### 解题思路
此处撰写解题思路
话说，这个题坑还是不少，(可能也是我有时候写递归结束条件不严谨，有些想当然)不过啊，总算过了。好了来说一说做这题的思路吧。首先题目强调路径不一定经过根节点.so...我们就先从根节点出发，把以根节点出发的路径都找到.嗯...我想过依据target<0来剪枝，其实这一步就发现了结点里面的值有可能是负的（想出这个测试用例的人真是个小机灵鬼）算了，放弃剪枝了，先用暴力法求出来把。然后根节点出发的dfs就写出来了。
接下来，就是遍历树里面每一个根节点。因为路径可能是从任何一个结点出发的.
先mark一下吧，虽然是纯暴力解法，不带一点优化，如果有大佬有更好的优化思路欢迎指教！！！
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
    int counter=0;
    void DFS(TreeNode* root,int target)
    {
       // if(target<0)
       // return;
        if(root==NULL)
        return;
        target=target-root->val;
        if(target==0)
        {
           counter++;
        }
        DFS(root->left,target);
        DFS(root->right,target);
    }
    void solve(TreeNode *root,int sum)
    {
       if(root==NULL)
       return;
       DFS(root,sum);
       solve(root->left,sum);
       solve(root->right,sum);
    }
    int pathSum(TreeNode* root, int sum) {
       solve(root,sum);
       return counter;
    }
};
```