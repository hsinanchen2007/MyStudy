# 86. 分隔链表
**思路：**
- 分割链表，可以创建两个头结点存储链表，一个连接小于目标值的节点，一个连接大于等于目标值节点。头结点为了消除第一个元素插入时与其他节点插入的不同。
- 分割后的链表要保持原序，两个链表插入元素可以采用尾插法的方式。
- 然后再将鬼界好的两个链表整合为一个链表。
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
    ListNode* partition(ListNode* head, int x) {
	    if(!head)	return head;
    	//头结点-1
        ListNode node_head_1(0);
        node_head_1.next = NULL;
        //头结点-2
        ListNode node_head_2(0);
        node_head_2.next = NULL;
        
        ListNode *node_tail_1 = &node_head_1;	//尾指针-1
        ListNode *node_tail_2 = &node_head_2;	//尾指针-2

        ListNode *temp;
        while(head){
        	temp = head->next;
        	if( head->val < x ){
        		head->next = node_tail_1->next;
        		node_tail_1->next = head;
        		node_tail_1 = head;
        	}else{
        		head->next = node_tail_2->next;
        		node_tail_2->next = head;
        		node_tail_2 = head;
        	}
        	head = temp;
        }
        node_tail_1->next = node_head_2.next;

        return node_head_1.next;
    }
};
```
