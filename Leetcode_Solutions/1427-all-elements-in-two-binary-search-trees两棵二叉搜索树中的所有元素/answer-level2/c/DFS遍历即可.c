### 解题思路
此处撰写解题思路

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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int DFSCnt(struct TreeNode* root, int cnt)
{
	int count = cnt;

	if (root == NULL) {
		return count;
	} else {
		count++;
	}

	if (root->left == NULL && root->right == NULL) {
		return count;
	}

	if (root->left != NULL) {
		count = DFSCnt(root->left, count);
	}
	if (root->right != NULL) {
		count = DFSCnt(root->right, count);
	}
	return count;
}

int DFSVal(struct TreeNode* root, int cnt, int base, int *arr)
{
	int count = cnt;

	if (root == NULL) {
		return count;
	} else {
		//printf("base %d count %d val %d \n", base, count, root->val);
		arr[base + count] = root->val;
		count++;
	}

	if (root->left == NULL && root->right == NULL) {
		return count;
	}

	if (root->left != NULL) {
		count = DFSVal(root->left, count, base, arr);
	}
	if (root->right != NULL) {
		count = DFSVal(root->right, count, base, arr);
	}
	return count;
}

int cmp_int(const void* _a , const void* _b)
{
    int* a = (int*)_a;    //强制类型转换
    int* b = (int*)_b;
    return *a - *b;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){

	int cnt1 = DFSCnt(root1, 0);
	int cnt2 = DFSCnt(root2, 0);
	*returnSize = cnt1 + cnt2;

	int *arr = (int *)malloc((cnt1 + cnt2) * sizeof(int));
	memset(arr, 0, (cnt1 + cnt2) * sizeof(int));

	(void)DFSVal(root1, 0, 0, arr);
	(void)DFSVal(root2, 0, cnt1, arr);

	qsort(arr, cnt1 + cnt2, sizeof(arr[0]), cmp_int);
	return arr;
}
```