### 解题思路
外层用while循环实现每一次循环剪除所有叶子结点，并将得到的叶子结点集合push到res中
内层递归实现查找到所有叶子节点
特殊情况，当剪除到最后一次时，返回空指针，表示循环结束

### 代码

```cpp
class Solution {
public:
	TreeNode* remove(TreeNode* root, vector<int>& ve) {
		if (root != NULL) {
			//如果root是叶子节点，代表最后一次操作
			//返回空指针即可
			if (root->left == NULL&&root->right == NULL) {
				ve.push_back(root->val);
				return NULL;
			}
			//左孩子
			//1.如果是叶子节点，则push进ve，并且移除
			//2.如果不是叶子节点，则继续往下remove
			if (root->left != NULL) {
				if (root->left->left == NULL&&root->left->right == NULL) {
					ve.push_back(root->left->val);
					root->left = NULL;
				}
				else {
					remove(root->left, ve);
				}
			}
			//右孩子
			if (root->right != NULL) {
				if (root->right->left == NULL&&root->right->right == NULL) {
					ve.push_back(root->right->val);
					root->right = NULL;
				}
				else {
					remove(root->right, ve);
				}
			}
			return root;
		}
	}

	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>>res;
		if (root == NULL) return res;
		while (root != NULL) {
			vector<int>ve;
			root=remove(root, ve);
			res.push_back(ve);
		}
		return res;
	}
};
```