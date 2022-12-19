### 解题思路
本质上是一个树的遍历问题。没什么特别要求的话，递归的代码比较简洁。选择递归。
- `isSubStructure`中根节点如果相等，进一步比较剩下的子树结构 `doesTree1HasTree2`。
- 比较子树返回的条件是，如果A为NULL，到A的叶节点了，B还不为空，那肯定不符合要求，返回false。如果B空了，A还没空，那么说明B都被A包含了，返回true。如果都没空，还要继续比较，如果值不相等，返回false。如果相等，那么递归，确认AB的左节点和右节点分别都相等。
- `isSubStructure`中根节点如果不相等，或者后续子树不包含，也就是res保持为false。就继续A的左节点与B比较。如果也不行，就A得右节点与B比较。直到A或者B到达叶节点。


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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)
            return false;
        bool res = false;
        if(A->val == B->val)
        {
            res = doesTree1HasTree2(A,B);
        }
        if(!res)
            res = isSubStructure(A->left,B);
        if(!res)
            res = isSubStructure(A->right,B);
        return res;
    }
    bool doesTree1HasTree2(TreeNode* A, TreeNode* B)
    {
        if(B == NULL)
            return true;
        if(A == NULL)
            return false;
        if(A->val != B->val)
            return false;
        return doesTree1HasTree2(A->left,B->left) && doesTree1HasTree2(A->right,B->right);
    }
};
```