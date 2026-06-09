### 解题思路
我们看一下这个问题，当我们遍历到一个节点时，再判断这个节点能不能是BST中的一个节点，我们需要从子树中获得以下的信息:(1)左右子数的最大值和最小值(lmin,lmax,rmin,rmax) (2)当前节点的值与lmax和rmin的大小关系 (3)左右子树是否为有效的BST。。当左右子树均为有效的BST时，并且，lmax < root->val < rmin时，valid = true;count = lcount+right+1;
不成立时，valid = false;count = max(lcount,rcount);再进一步更新min_val,max_val。。。最后，还需要处理下root==NULL的情况。

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
    void dfs(TreeNode* root,bool& valid,int& count,long& min_val,long& max_val){
        if(!root){
            valid = true;
            min_val = LONG_MAX;
            max_val = LONG_MIN;
            count = 0;
            return;
        }

        bool lvalid = false,rvalid = false;
        long lmin = LONG_MAX,rmin = LONG_MAX;
        long lmax = LONG_MIN,rmax = LONG_MIN;

        int lcount = 0;
        int rcount = 0;
        dfs(root->left,lvalid,lcount,lmin,lmax);
        dfs(root->right,rvalid,rcount,rmin,rmax);

        min_val = min(lmin,min(rmin,(long)root->val));
        max_val = max(lmax,max(rmax,(long)root->val));

        if(lvalid && rvalid && lmax < root->val && root->val <rmin){
            valid = true;
            count = lcount+rcount+1;
        }else{
            valid = false;
            count = max(lcount,rcount);
        }
    }

    int largestBSTSubtree(TreeNode* root) {
        bool valid = false;
        long min_val = LONG_MAX;
        long max_val = LONG_MIN;
        int count = 0;
        dfs(root,valid,count,min_val,max_val);
        return count;
    }
};
```