### 解题思路
暴力递归+记忆化搜索，但是更进一步的动态规划解法就不会了。

### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
	map<TreeNode*,int> memo;
	int tryRob(TreeNode* root) {
		if (!root)
			return 0;
		
		if (memo.find(root) != memo.end())
			return memo[root];

		int res1 = 0, res2 = 0;
		res1 += root->val;
		if (root->left) {
			if (root->left->left)
				res1 += tryRob(root->left->left);
			if (root->left->right)
				res1 += tryRob(root->left->right);
		}
		if (root->right) {
			if (root->right->left)
				res1 += tryRob(root->right->left);
			if (root->right->right)
				res1 += tryRob(root->right->right);
		}


		if (root->left) 
			res2 += tryRob(root->left);

		if (root->right)
			res2 += tryRob(root->right);

		int res = max(res1, res2);
		memo.insert(pair<TreeNode*,int>(root, res));
	
		return res;
	}
public:
	int rob(TreeNode* root) {
		return tryRob(root);
	}
};
```