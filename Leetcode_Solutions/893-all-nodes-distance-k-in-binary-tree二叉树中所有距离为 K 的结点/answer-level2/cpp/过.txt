![2.png](https://pic.leetcode-cn.com/34b36cdb77c12a037c053ff188b1116eb85f6242db8072d99983dcbd70d6df6b-2.png)
### 解题思路
1. 获取到目的节点的路径
2. 根据路径获取对应层数的节点并保存

### 关键
1. 如何获取到目的节点的路径?
2. 因为是从下至上,所以如何不重复的取到对应层数的节点?

### 代码

```cpp
class Solution {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		stack<TreeNode*> st;
		vector<int> ret;
		st.push(root);
		FindTarget(st, target);
		TreeNode* last = nullptr;
		while (!st.empty())
		{
			getchild(ret, st.top(), last, K);
			last = st.top();
			K--;
			st.pop();
		}
		return ret;
	}
	void FindTarget(stack<TreeNode*>& st, TreeNode* target)
	{
		if (st.top() == nullptr || st.top() == target)
			return;
		st.push(st.top()->left);
		FindTarget(st, target);
		if (st.top() != target)	st.pop();
		st.push(st.top()->right);
		FindTarget(st, target);
		if (st.top() != target)	st.pop();
	}
	void getchild(vector<int>& ret, TreeNode* root,TreeNode* last,int n)
	{
		if (root == nullptr||root==last)	return;
		if (n == 0)
			ret.push_back(root->val);
		getchild(ret,root->left, last, n - 1);
		getchild(ret,root->right, last, n - 1);
	}
};
```