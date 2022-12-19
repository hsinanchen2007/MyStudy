### 解题思路
此处撰写解题思路
双重递归了，先找到相等的那个节点然后再从那个地方开始遍历，子结构和子树不同，我把dfs中哪一行注释了，就变成子结构了,如果不注释，就用来解答子树问题。
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
public:  //子树 和子结构 是不一样的 
    bool dfs(TreeNode*t1,TreeNode*t2)
    {   if(t1&&t2)
        return (t1->val==t2->val)&&dfs(t1->left,t2->left)&&dfs(t1->right,t2->right);
        else if(t1==NULL&&t2!=NULL) return false;
        //else if(t1!=NULL&&t2==NULL) return false;把这个条件注释
        return true;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL) return false;
        if(A==NULL) return false;
        if(A->val==B->val) return dfs(A,B);    
        else return isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
};
```