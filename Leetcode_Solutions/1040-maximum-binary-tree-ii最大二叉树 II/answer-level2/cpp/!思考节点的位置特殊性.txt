### 解题思路
解题的突破点在于，最后一个位置是有特殊性的，即附加节点B的值
1、大于根节点，在根节点的右上方，B->left=root；
2、小于根节点，一直往右找到那个小于附加点的节点A（因为附加点B肯定在最右边），然后使得B->left=A, pre->right=B.

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* kong=new TreeNode(0);
        TreeNode* pre=kong;
        kong->right=root;//kong->right的才是真正的root节点
        TreeNode* cur=root;
        while(cur!=NULL && cur->val > val){
            pre=cur;
            cur=cur->right;//因为val是附加在最右端的，所以始终往右走
        }
        TreeNode* node=new TreeNode(val);
        node->left=cur;//val在最右端，所以其余节点都在左端
        pre->right=node;
        return kong->right;
    }
};
```