### 解题思路
递归创建

### 代码

```cpp

class Solution {
public:

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preorder_begin, int preorder_end, int inorder_begin, int inorder_end)
	{
		if (inorder_begin > inorder_end)
		{
			return nullptr;
		}

		//从中序数组中找到根的位置  根的值：preorder.at(preorder_begin)
		int inorder_root_index = find(inorder, inorder_begin, inorder_end, preorder.at(preorder_begin));

		TreeNode* root = new TreeNode(preorder.at(preorder_begin));

		//中序数组划分为左子树、右子树
		//左子树：inorder_begin 到 inorder_root_index - 1   元素个数为 inorder_root_index - inorder_begin
		//右子树：inorder_root_index + 1 到 inorder_end

		//先序数组也划分为左子树、右子树
		//左子树：preorder_begin + 1 到  preorder_begin + inorder_root_index - inorder_begin 
		//右子树：preorder_begin + inorder_root_index - inorder_begin + 1 到 preorder_end

		root->left = buildTree(preorder, inorder, preorder_begin + 1, preorder_begin + inorder_root_index - inorder_begin, 
			inorder_begin, inorder_root_index - 1);

		root->right = buildTree(preorder, inorder, preorder_begin + inorder_root_index - inorder_begin + 1, preorder_end, 
			inorder_root_index + 1, inorder_end);

		return root;
	}


	int find(const vector<int>& v, int begin, int end, int target)
	{
		for (int i = begin; i <= end; ++i)
		{
			if (target == v.at(i))
			{
				return i;
			}
		}
		return -1;
	}

};
```