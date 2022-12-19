![1580906884(1).png](https://pic.leetcode-cn.com/a3ff3c7baaf2262821039e8dc5c30dd2a4e8c9da4c1dea909dfa0180dca864f9-1580906884\(1\).png)


### 解题思路
直接看代码，0ms

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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if(p == NULL && q == NULL){
		return true;
	}else if(p == NULL &&  q != NULL){
			return false;
	}else if (p != NULL &&  q == NULL){
		return false;
	}else {
		if(p->val != q->val){
			return false;
		}else {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
}

```