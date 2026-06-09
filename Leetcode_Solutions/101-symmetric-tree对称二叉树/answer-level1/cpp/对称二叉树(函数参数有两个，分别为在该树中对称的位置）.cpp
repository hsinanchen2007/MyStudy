### 解题思路
写树类题目要知道三步。。
本题目：看成两棵树，每棵树节点的对应位置要相等。。

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
public:    //递归 迭代
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return par(root->left ,root->right);
    }
    bool par(TreeNode *rleft,TreeNode *rright){
        if(!rleft&&!rright) return true;             //终止条件
        if(rright==NULL||rleft==NULL) return false;
        if(rright->val==rleft->val) //该节点处应该做什么，怎么进行递归，只要处理好该节点做什么，递归只是按步骤重复执行而已。
            return par(rleft->left,rright->right)&&par(rleft->right,rright->left); 
        return false;                                //返回什么
    }
};
```