### 解题思路
首先对A进行DFS,找到A中和B的根节点相等的节点,记为A\`。
对于每一个A\`,用B进行DFS判断A\`是否包含B。

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
    bool dfs1(TreeNode* B,TreeNode* A)
    {
        if(!B) return true; //遍历到了B的边界，说明前面都已经符合了，所以返回true
        if(!A) return false;//遍历到A的边界，而B还没有到边界，所以B肯定不是A的子树，所以返回false
        if(B->val != A->val) return false; //在遍历的过程中，如果A和B节点的值不相等，可以直接返回false 否则还要遍历B
        return dfs1(B->left,A->left) && dfs1(B->right,A->right);
    }
    bool dfs(TreeNode* A,TreeNode* B)
    {
        if(!A || !B) return false; //如果B和A都是空的话那么就不存在子树一说了
        if(A->val == B->val)
        {
            if(dfs1(B,A)) return true;//A和B的值相等，那么就直接dfs1，遍历B。
        }
        return dfs(A->left,B)||dfs(A->right,B)//继续遍历A        
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {        
        return dfs(A,B);
    }
};
```