前面做过使用有序数组构造二叉搜索树的题目，因此最简单的暴力法则直接先将链表存储进数组，再套用之前的方法。
针对链表，可使用快慢指针slow_ptr和fast_ptr的方法定位其中点，非常巧妙。此外可再定义一个指针pre_ptr指向中点前一个节点，用于后面二分递归时左子树的有边界。
另外要注意的是递归出口，此解答中左右子树的递归出口是不同的。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
	TreeNode* sortedListToBST(ListNode* head) 
	{
		return buildBST(head, nullptr);
	}

	TreeNode* buildBST(ListNode* head, ListNode* tail)
	{
		/*右子树递归出口，以及当初始链表为空时的返回值*/
		if (head == nullptr)
		{
			return nullptr;
		}

		else
		{
			ListNode* pre_ptr = nullptr;
			ListNode* slow_ptr = head;
			ListNode* fast_ptr = head;

			/*使得slow_ptr指向链表中间*/
			while (fast_ptr != nullptr && fast_ptr->next != nullptr)
			{
				pre_ptr = slow_ptr;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next->next;
			}
			/*因pre_ptr将作为左子树的tail，需使其指向nullptr*/
			if (pre_ptr != nullptr)
			{
				pre_ptr->next = nullptr;
			}

			TreeNode* root = new TreeNode(slow_ptr->val);

			/*左子树递归出口，当只剩下一个节点的时候*/
			if (head == slow_ptr)
			{
				return root;
			}

			root->left = buildBST(head, pre_ptr);
			root->right = buildBST(slow_ptr->next, tail);

			return root;
		}
	}
};
```