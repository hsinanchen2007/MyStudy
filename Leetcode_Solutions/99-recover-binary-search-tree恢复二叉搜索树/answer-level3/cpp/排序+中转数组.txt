### 解题思路
借助一个存放树节点指针的数组和一个数节点值得数组。在中序遍历过程中将节点和节点值分别保存到两个数组中，然后将节点值数组升序排列，最后将排序后的数组值一次赋给树节点。

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
    void recoverTree(TreeNode* root) {

        //数组里面存放指向中序遍历各个树节点指针,所以修改list[i]->val就是修改树节点的val
        vector<TreeNode*> list;

        //存放中序遍历的节点值
        vector<int> value;

        inorder(root,list,value);

        sort(value.begin(),value.end());

        //此时 list[i]->val 依次是：3,2,1  value数组中的值是：1,2,3
        for(int i = 0;i < value.size();++i)
        {
            list[i]->val = value[i];
        }
        //此时 list[i]->val 依次是：1,2,3即树节点的值已经安升序排列
    }
    void inorder(TreeNode* root,vector<TreeNode*> &list,vector<int> &value)
    {
        if(!root) return ;

        inorder(root->left,list,value);

        list.push_back(root);
        value.push_back(root->val);

        inorder(root->right,list,value);
    }

};
```