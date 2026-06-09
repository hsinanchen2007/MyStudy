# 234. 回文链表
慢！
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
    bool isPalindrome(ListNode* head) {
		ListNode* rear;
		ListNode* temp;
		while(1){
			if( head == NULL || head->next == NULL ){
				return true;
			}
			
			ListNode* rear = head;
			while( rear->next != NULL ){
				temp = rear;
				rear = rear->next;
			}
			
			if( rear->val == head->val ){
				temp->next = NULL;
				head = head->next;
			}else{
				return false;
			}
		}
    }
};
```
