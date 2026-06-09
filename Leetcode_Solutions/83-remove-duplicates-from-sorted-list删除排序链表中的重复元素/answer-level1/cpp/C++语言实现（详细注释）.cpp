### 解题思路
	这题主要考察的是链表的删除操作。因为所给链表是有序的，我们可以从当前节点开始和下一个节点比较，如果两个节点值相同，则删除后一个节点，一直到两个节点值不相同，此时我们将指针指向后一个节点，再进行上述操作，一直到遍历结束。

### 代码

```cpp
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
    ListNode* deleteDuplicates(ListNode* head) 
    {
    if(head == NULL)  //如果所给链表为空直接返回，否则在执行ptr->next这部操作时会因为ptr为NULL而造成执行时错误
        return head;
	ListNode* ptr{ head };  //遍历的指针
	while (ptr->next != NULL)  //遍历首个元素到第倒数第二个元素，因为是逐个向后比较，最后一个元素会被比较到，这样是正确的
	{
		if (ptr->val == ptr->next->val)  //和后一个元素比较
		{
			ListNode* p = ptr->next;  
			ptr->next = p->next;  //删除操作
			delete p;  //释放空间
		}
		else
		{
			ptr = ptr->next;  //移动到后一个元素
		}
	}
	return head;  //返回首个节点
    }
};
```