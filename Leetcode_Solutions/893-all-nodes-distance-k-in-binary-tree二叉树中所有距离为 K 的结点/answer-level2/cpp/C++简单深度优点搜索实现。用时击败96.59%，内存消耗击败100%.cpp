### 解题思路
题目给的是target的节点，所以target节点以下的节点可以直接添加到里面去。
其它的节点，通过先找到target节点，然后通过返回值确定它们之间的距离，这样就能够把所有的都添加进去。
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
	vector<int> ans;

	int dfsFind(TreeNode* root, int target, int k) {
		if (target == root->val) return 1;  // 发现目标节点之间返回1
		if (root->left) {
			int tmp = dfsFind(root->left, target, k);
			if (-1 != tmp) {			// 不是-1，这说明在左子树找到了
				// 看一看距离是否等于k，否则直接添加并且返回-1
				// 因为不管现在往上找，还是往右子树找都需要增加距离
				if (k == tmp) {			
					ans.push_back(root->val);
					return -1;
				}
				// 找右子树
				if (root->right) dfsAdd(root->right, k - tmp, 1);
				// 返回非-1的值，代表往上找
				return  tmp + 1;
			}
		}
		if (root->right) {
			int tmp = dfsFind(root->right, target, k);
			if (-1 != tmp) {
				if (k == tmp) {
					ans.push_back(root->val);
					return -1;
				}
				if (root->left) dfsAdd(root->left, k - tmp, 1);
				return  tmp + 1;
			}
		}
		return -1;
	}

	void dfsAdd(TreeNode* root, int k, int deep) {
		if (k == deep) {
			ans.push_back(root->val);
			return;
		}
		if (root->left) dfsAdd(root->left, k, deep+1);
		if (root->right) dfsAdd(root->right, k, deep+1);
	}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K == 0) {	// 等于0，直接返回
        	ans.push_back(target->val);
        	return ans;
        }
        dfsAdd(target, K, 0); // 直接添加target的满足要求的子节点
        dfsFind(root, target->val, K);
        return ans;
    }
};
```