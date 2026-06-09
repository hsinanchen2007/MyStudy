### 解题思路
先将链表转化成数组，再将数组转化为树
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


#define max 20000
struct TreeNode *arrtoTree(int *nums, int low, int high) {
	if (low > high)
		return NULL;
	struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	int mid = (low + high + 1) / 2;
	p->val = nums[mid];
	p->left = arrtoTree(nums, low, mid - 1);
	p->right = arrtoTree(nums, mid + 1, high);
	return p;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	int i = 0;
	int nums[max];
	while (head != NULL) {
		nums[i++] = head->val;
		head = head->next;
	}
	return arrtoTree(nums, 0, i - 1);
}
```