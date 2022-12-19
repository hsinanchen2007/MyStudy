### 解题思路
类似于通过前序遍历和中序遍历思想
由于后序遍历的最后一个元素一定是根节点，因此容易获得根节点，再通过中序遍历，可以知道左右子树的位置及个数
对于中序遍历的左右子树，再递归进行构建



### 代码

```cpp
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
	}
	TreeNode* create(vector<int>& inorder, vector<int>& postorder, int inL,int inR, int postL, int postR)
	{
		if (postL > postR) return NULL;//递归边界
		TreeNode* head = new TreeNode(postorder[postR]);
		//求后序遍历根节点在中序遍历中的位置
		int k;
		for (k=inL;k<=inR;k++)
		{
			if (inorder[k]==postorder[postR])
			{
				break;
			}
		}
		//右子树结点的个数
		int numsRight = inR - k;
		head->left = create(inorder, postorder, inL, k - 1, postL, postR-numsRight-1);
		head->right = create(inorder, postorder, k + 1, inR, postR - numsRight, postR - 1);
		//返回根节点
		return head;
	}
};
```