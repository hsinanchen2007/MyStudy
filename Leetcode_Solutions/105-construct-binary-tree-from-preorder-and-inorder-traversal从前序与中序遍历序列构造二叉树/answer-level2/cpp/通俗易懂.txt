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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())
            return NULL;
        int num = inorder.size();
        vector<int> pre_left, pre_right, in_left, in_right; 
        //创建根节点，根节点肯定是前序遍历的第一个数
        TreeNode* head = new TreeNode(preorder[0]);

        //找到根节点再中序遍历的位置，放在gen中
        int gen = 0;
        for(int i=0;i<num;i++)
        {
            if(inorder[i]==preorder[0])
            {
                gen=i;
                break;
            }
        }
        //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
        //左子数：
        for(int i = 0;i<gen;i++)
        {
            in_left.push_back(inorder[i]);
            pre_left.push_back(preorder[i+1]);
        }
        for(int i = gen+1;i<num;i++)
        {
            in_right.push_back(inorder[i]);
            pre_right.push_back(preorder[i]);
        }

        head->left=buildTree(pre_left,in_left);
        head->right=buildTree(pre_right,in_right);

        return head;
    }
};
```