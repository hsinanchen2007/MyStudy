### 解题思路
使用双递归
第一个递归遍历整个树，根据当前节点的val得到需要查找的另外一个数（k-val）
第二个递归遍历整个数，查找k-val是否在树上

![image.png](https://pic.leetcode-cn.com/4a8af4e94675671e265d6c62327e9d253b88dc9fb98cf65614f3380ebee27f74-image.png)


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find(struct TreeNode* root, int val, bool *rlt)
{
	if (root == NULL || *rlt == true) {
		return;
	}
	if (root->val == val) {
		*rlt = true;
	}
	if (val > root->val) {
		find(root->right, val, rlt);
	} else {
		find(root->left, val, rlt);
	}
	return;
}
void trans(struct TreeNode* root, int k, struct TreeNode* curnode, bool *rlt)
{
	int needVal;
	if (curnode == NULL) {
		return;
	}
	needVal = k - curnode->val;
	if (needVal != curnode->val) {
		find(root, needVal, rlt);
	}
	if (*rlt != true) {
		trans(root, k, curnode->left, rlt);
	}
	if (*rlt != true) {
		trans(root, k, curnode->right, rlt);
	}
	return;
}
bool findTarget(struct TreeNode* root, int k){
	bool rlt = false;
	trans(root, k, root, &rlt);
	return rlt;
}
```