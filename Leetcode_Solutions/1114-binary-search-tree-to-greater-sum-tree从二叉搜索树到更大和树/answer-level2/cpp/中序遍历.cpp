### 解题思路
第一次中序遍历对节点自动排序，接着求后缀和，接着再把后缀和通过后序遍历传回树。

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
void traveler(TreeNode*ptr,vector<int>&hold)
{
	if (ptr->left != NULL)
	{
		traveler(ptr->left,hold);
	}
    hold.push_back(ptr->val);
	if (ptr->right != NULL)
		traveler(ptr->right,hold);
}
void traveler2(TreeNode*ptr,int*sumOfN,int&curr)
{
	if (ptr->left != NULL)
	{
		traveler2(ptr->left,sumOfN,curr);
	}
	ptr->val=sumOfN[curr++];
	if (ptr->right != NULL)
		traveler2(ptr->right,sumOfN,curr);
}
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
        return root;
        vector<int>hold;
        traveler(root,hold);
        int*sumOfN=new int[hold.size()];
        sumOfN[hold.size()-1]=hold[hold.size()-1];
        for(int i=hold.size()-2;i>=0;i--)
        sumOfN[i]=hold[i]+sumOfN[i+1];
        int curr=0;
        traveler2(root,sumOfN,curr);
        return root;
    }
};
```