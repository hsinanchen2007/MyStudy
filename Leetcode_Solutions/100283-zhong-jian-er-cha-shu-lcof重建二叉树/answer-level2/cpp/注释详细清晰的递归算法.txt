前序遍历为：中左右；中序遍历为：左中右
解此题最主要用到一个点便是，**中序遍历根节点所在位置既是中序遍历左右子树分界点，是前序遍历左右子树的分界点**
于是便可将两个容器的元素分别拆分给左右子树，实现递归
```cpp
class Solution
{
public:
	/*前序遍历为：中左右；中序遍历为：左中右*/
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0 && inorder.size() == 0)
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[0]);
		/*在中序遍历中找到根节点的位置*/
		/*此位置既是中序遍历左右子树分界点，////也是前序遍历左右子树分界点////*/
		vector<int>::iterator mid = find(inorder.begin(), inorder.end(), preorder[0]);
		/*确定左子树节点的个数*/
		int left_size = mid - inorder.begin();

		/*根据两种遍历的特点，确定左子树和右子树所对应的两种遍历元素的容器*/
		vector<int> left_pre(preorder.begin() + 1, preorder.begin() + left_size + 1);
		vector<int> right_pre(preorder.begin() + left_size + 1, preorder.end());
		vector<int> left_in(inorder.begin(), mid);
		vector<int> right_in(mid + 1, inorder.end());

		/*递归*/
		root->left = buildTree(left_pre, left_in);
		root->right = buildTree(right_pre, right_in);

		return root;
	}
};
```