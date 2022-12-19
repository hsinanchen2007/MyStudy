### 解题思路
方法一：递归
方法二：BFS
### 代码
#### 方法一

```cpp
//递归求解
//考虑只有一个结点的树
//对于该树，左子树高度为leftDepth
//右子树高度为rightDepth
//比较两者谁大，大者+1，即为该树的高度
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return leftDepth < rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
};
```

#### 方法二
```cpp
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		queue<TreeNode*> q;
		int layer = 0;
		q.push(root);
		while (!q.empty()) {
			int qSize = q.size();
			if (qSize > 0) layer++;
			for (int i=0;i<qSize;i++)
			{
				TreeNode* front = q.front();
				q.pop();
				if (front->left != NULL) q.push(front->left);
				if (front->right != NULL) q.push(front->right);
			}
		}
		return layer;
	}
};
```