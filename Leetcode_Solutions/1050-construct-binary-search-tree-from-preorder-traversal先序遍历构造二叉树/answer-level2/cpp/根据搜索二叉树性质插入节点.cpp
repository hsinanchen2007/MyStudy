### 解题思路
遍历数组，插入每一个节点。
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
    void inserts(TreeNode* &root, int x)
    {
        if(root == NULL)  //当前位置为空，就是插入的地方
        {
        root = new TreeNode(x);
        return ;
        }
        if(root->val > x) inserts(root->left, x);  //如果当前二叉树节点的值大于要插入树的节点的值，就向左寻找插入位置
        else inserts(root->right, x);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* ans = NULL;  //一定要先声明为空，我第一次就是这里疯狂报错。。。
        if(preorder.size() < 1)
        return ans;
        for(int i = 0; i < preorder.size(); i ++)
        inserts(ans, preorder[i]);  //遍历数组，插入每一个节点
        return ans;
    }
};
```