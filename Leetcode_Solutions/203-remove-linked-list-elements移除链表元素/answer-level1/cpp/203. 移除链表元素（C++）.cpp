# 203. 移除链表元素
**思路：**

- 首先创建一个头节点，用于消除第一个节点在删除时与其他结点的差别。并把头结点的next指针指向传来的链表第一个数据节点。
- 然后从头结点开始遍历链表，如果遍历到的节点下一个节点的数值为val，就把下个节点剔除。然后重新查看该节点的下个新节点是否为valval。
- 如果下个节点不是val，就后移，直到写个节点为空。
**完整代码：**
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode pre_head(0);
		pre_head.next = head;
		ListNode* temp = &pre_head;
		while( temp->next != NULL ){
			if( temp->next->val == val ){
				temp->next = temp->next->next;
			}else{
				temp = temp->next;
			}
		}
		return pre_head.next;
    }
};
```
