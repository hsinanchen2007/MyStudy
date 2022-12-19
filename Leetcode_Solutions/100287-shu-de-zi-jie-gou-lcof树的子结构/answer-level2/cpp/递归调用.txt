### 解题思路
此处撰写解题思路

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr)
            return false;
        bool ans=isSub(A,B);//B非空
        return ans;
    }
    bool isSub(TreeNode* a,TreeNode* b){//b非空
        if(a==nullptr){
           // if(b!=nullptr)
           //     return false;
           // else
                return false;
        }
        bool ans;
        if(a->val==b->val)
            ans=(isSame(a,b) || isSub(a->left,b) || isSub(a->right,b));
        else
            ans=(isSub(a->left,b) || isSub(a->right,b));
        return ans;
    }
    bool isSame(TreeNode* a,TreeNode* b){
        bool ans;
        if(a!=nullptr && b!=nullptr){
            if(a->val==b->val)
                return (isSame(a->left,b->left) && isSame(a->right,b->right));
            else
                return false;
        }
        if(b==nullptr)
             return true;
        else
            return false;
    }
};
```