


### 代码

```cpp
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* create(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR)
	{
		//递归边界
		if (preL > preR) return NULL;

		TreeNode* head = new TreeNode(preorder[preL]);//创建节点并赋值

		//先序遍历的头节点在中序遍历中的位置
		int k;
		for (k = inL; k <= inR; k++)
		{
			if (preorder[preL] == inorder[k])
			{
				break;
			}
		}
		//左子树结点的个数，方便区间的填写
		int numsLeft = k - inL;
		//对于head的左子树继续构建
		head->left = create(preorder, inorder, preL + 1, preL + numsLeft, inL, inL + k - 1);
		//对于head的右子树继续构建
		head->right = create(preorder, inorder, preL +numsLeft+1, preR, k + 1, inR);
		//返回根结点地址
		return head;
	}
};
```