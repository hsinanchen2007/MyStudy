# 106. 从中序与后序遍历序列构造二叉树
与105题类似，但先序遍历改为了后序遍历。
后序遍历的访问顺序：`left->right->root`
翻转后序遍历访问顺序：`root->right->left`
先序遍历的访问顺序：`root->left->right`
可以发现反转后的后序遍历与先序遍历只有左右子树顺序不同，所以：
1.我们先将后序遍历翻转。
2.再将**先序遍历与中序遍历递归生成二叉树**的**左右递归顺序翻转**即可。
```
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
private:
	int postorder_num = 0;
public:
	void buildTreeRecursion(vector<int>& postorder, vector<int>& inorder ,TreeNode *&root,int inorder_left ,int inorder_right){
		if( postorder_num > postorder.size()-1 || inorder_left > inorder_right )
			return;

		int temp = postorder[postorder_num];
		root = new TreeNode(temp);

		++postorder_num;

		for( int i = inorder_left; i <= inorder_right; ++i ){
			if( inorder[i] == temp ){
				buildTreeRecursion(postorder,inorder,root->right,i+1,inorder_right);
				buildTreeRecursion(postorder,inorder,root->left,inorder_left,i-1);
			}
		}
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	//后序遍历翻转
    	reverse(postorder.begin(),postorder.end());

        TreeNode *root = NULL;
    	if( postorder.size() > 0)
    		buildTreeRecursion(postorder,inorder,root,0,inorder.size()-1);

        return root;
    }
};
```
