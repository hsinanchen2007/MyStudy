# 105. 从前序与中序遍历序列构造二叉树
先序遍历和中序遍历都是深度优先二叉树遍历。
- 先序遍历的访问顺序：`root->left->right`
- 中序遍历的访问顺序：`left->root->right`

先序遍历与中序遍历的区别是根节点被访问顺序不同：
- 先序访问遇到根节点后就立即访问然后递归访问左右子树；
- 而中序遍历是在其递归访问完的所有左子孙节点后访问完成后在访问根节点。

**所以先序遍历可以显示出每个节点的被访问顺序；而中序遍历可以显示出该节点的左右子孙节点信息。**

中序遍历中：
- 所有在该节点的左子孙节点，中序位置都在该节点左边。
- 同理，该节点右子孙节点，中序位置都在该节点右边。


我们就可以把问题归结为两颗子树的问题（利用`left/right`-左右下边划分），不断顺序的从先序遍历中取出元素，在中序遍历中找他其位置，划分左右子树，在左右子树中重复刚才的过程。直到取出所有的元素。
完整代码：
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
	int preorder_num = 0;
public:
	void buildTreeRecursion(vector<int>& preorder, vector<int>& inorder ,TreeNode *&root,int inorder_left ,int inorder_right){
		if( preorder_num > preorder.size()-1 || inorder_left > inorder_right )
			return;

		int temp = preorder[preorder_num];
		root = new TreeNode(temp);

		++preorder_num;

		for( int i = inorder_left; i <= inorder_right; ++i ){
			if( inorder[i] == temp ){
				buildTreeRecursion(preorder,inorder,root->left,inorder_left,i-1);
				buildTreeRecursion(preorder,inorder,root->right,i+1,inorder_right);
			}
		}
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	TreeNode *root = NULL;
    	if( preorder.size() > 0)
    		buildTreeRecursion(preorder,inorder,root,0,inorder.size()-1);

        return root;
    }
};
```
