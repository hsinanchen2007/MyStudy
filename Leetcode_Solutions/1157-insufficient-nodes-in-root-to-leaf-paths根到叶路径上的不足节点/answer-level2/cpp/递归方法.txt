### 解题思路
这个方法应该是比较容易想到的一种方法。
首先遍历到叶节点，判断当前和是否大于limit：
     (1)若和大于等于limit，则返回1.
     (2)反之，则返回-1.
当递归返回至上一层时：
     (1)若L为-1，则删除左侧节点。其中需要注意的是，若右节点为NULL，则继续返回-1.
     (2)若R为-1，则删除右侧节点。若左节点为NULL，则直接返回-1.
     (3)若L和R为1，则返回1.
当到达根结点时，若d=-1则直接返回NULL否则二返回root。

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int d = helper(root,limit,0);
        if(d==-1){
            return NULL;
        }
        return root;
    }
    int helper(TreeNode* root, int limit,int cur_val){
        if(root==NULL){
            if(cur_val<limit){
                return -1;
            }
            return 1;
        }

        int L = helper(root->left,limit,cur_val+root->val);
        int R = helper(root->right,limit,cur_val+root->val);

        if(L==-1 && R==-1){
            root->left=NULL;
            root->right=NULL;
            return -1;
        }
        if(L==-1){
            root->left=NULL;
            if(root->right==NULL){
                return -1;
            }
        }
        if(R==-1){
            root->right=NULL;
            if(root->left==NULL){
                return -1;
            }
        }

        return 1;
    }
};
```