# 标题141. 环形链表（C++ 快慢指针）
**采用快慢指针的方式:**
快指针每次走两个链表单元，慢指针每次走一个链表单元。

- 如果快指针识别到下一步中存在NULL，则次链表无循环。
- 如果存在循环，快指针会在x步后追上慢指针，此时快慢指针指向统一节点。
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head == NULL || head->next == NULL ){
			return false;
		}
		
		//快慢指针
		ListNode *fast = head;
		ListNode *low = head;
		while( fast->next != NULL && fast->next->next != NULL ){
			low = low->next;
			fast = fast->next->next;
			
			if( low->val == fast->val ){
				return true;
			}
		}
		return false;
    }
};
```
