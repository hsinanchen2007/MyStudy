### 解题思路
按照原始的思路来，进行树前序遍历，从遍历的当前节点，计算从当前节点向下能产生多少种可能。
![image.png](https://pic.leetcode-cn.com/c8f3e13d9da05dec2149f99dd760cd94dfbceb735c1dd45f68b2a74885683e68-image.png)

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

void sumCnt(struct TreeNode* root, int expSum, int curSum, int *cnt)
{
	if (root == NULL) {
		return;
	}
	curSum += root->val;
	if (curSum == expSum) {
		*cnt = *cnt + 1;
	}
	sumCnt(root->left, expSum, curSum, cnt);
	sumCnt(root->right, expSum, curSum, cnt);
	return;
}
void transTree(struct TreeNode* root, int expSum, int *cnt)
{
	if (root == NULL) {
		return;
	}
	sumCnt(root, expSum, 0, cnt);
	transTree(root->left, expSum, cnt);
	transTree(root->right, expSum, cnt);
}
int pathSum(struct TreeNode* root, int sum){
	int cnt = 0;
	transTree(root, sum, &cnt);
	return cnt;
}
```