### 解题思路
将链表指针存储到数组中，这样中点计算就是直接可以使用线性值，不需要遍历，但是需要O(n)的空间
![image.png](https://pic.leetcode-cn.com/4ba55a9fc5e3fbbd18f9d3145654bfbd2a4253a2dc212e33ff30234775122971-image.png)

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
#define MY_OK 0
#define MY_FAIL (-1)

int cntList(struct ListNode* head)
{
	int cnt = 0;
	while (head != NULL) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

int createArr(struct ListNode ***arr, struct ListNode* head, int cnt)
{
	int i;
	struct ListNode **a = NULL;
	a = (struct ListNode**)calloc(cnt, sizeof(struct ListNode*));
	if (a == NULL) {
		return MY_FAIL;
	}
	for (i = 0; i < cnt; i++) {
		a[i] = head;
		head = head->next;
	}
	*arr = a;
	return MY_OK;
}

struct TreeNode* process(struct ListNode** arr, int left, int right)
{
	int mid;
	struct TreeNode *node = NULL;
	
	mid = (left + right + 1) / 2;
	node = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	if (node == NULL) {
		return NULL;
	}
	node->val = arr[mid]->val;
	if (left < mid) {
		node->left = process(arr, left, mid - 1);
	}
	if (right > mid) {
		node->right = process(arr, mid + 1, right);
	}
	return node;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
	int i, cnt, ret;
	struct ListNode **arr = NULL;
	struct TreeNode *rlt = NULL;
	cnt = cntList(head);
	if (cnt == 0) {
		return NULL;
	}
	ret = createArr(&arr, head, cnt);
	if (ret != MY_OK) {
		return NULL;
	}
	rlt = process(arr, 0, cnt - 1);
	free(arr);
	return rlt;
}
```