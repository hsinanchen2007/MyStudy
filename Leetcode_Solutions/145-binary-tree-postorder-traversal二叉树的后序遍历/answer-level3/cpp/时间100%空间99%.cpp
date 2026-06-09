### 思路
二叉树的前序遍历为中左右，后序遍历为左右中。所以想到利用反向前序遍历，然后再reverse一下得到结果

### C++vector的reverse
vector的反转我用for循环实现时间0ms内存8.8mb
但是用内置函数reverse(v.begin(),v.end())时间直接飙升到8ms，内存减少了0.3mb
最后还是用for循环吧

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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> S;
		vector<int> v;
		while (root != NULL || !S.empty()) {
			while (root != NULL) {
				// 右子树压栈
				S.push(root);
				v.push_back(root->val);
				root = root->right;
			}
			if (!S.empty()) {
				root = S.top();
				S.pop();
				root = root->left;
			}
		}
		int len = v.size();
		for (int i = 0; i < len/2; i++) {
			v[i] = v[i] + v[len - i - 1];
			v[len - i - 1] = v[i] - v[len - i - 1];
			v[i] = v[i] - v[len - i - 1];
		}
		return v;
	}
};
```