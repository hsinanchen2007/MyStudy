### 解题思路
获取有效偏移量，设链表长len，有效偏移量offset=k%len，用front链表记录第1个到第len-offset的节点值，用back链表记录最后offset个节点，back的最后一个节点的naxt指向front，将两个链表拼合后返回back的头结点即可。

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
    ListNode* rotateRight(ListNode* head, int k) {
		// 空链表，0偏移，链表长度为1，直接返回头结点
		if(k==0||head==NULL||head->next==NULL)
			return head;
		ListNode *p=head,*front=new ListNode(0),*back=new ListNode(0),*ptr1=front,*ptr2=back;
		// 记录链表长度
		int len=0;
		while(p)
		{
			len++;
			p=p->next;	
		}
		// 计算有效偏移，如果偏移的是链表长度的整数倍，相当于没有偏移直接返回头结点
		if(k%len==0)
			return head;
		int offset=k%len;
		p=head;
		for(int i=0;i<len;i++)
		{
		// 记录前len-offset个节点
			if(i<len-offset)
			{
				ListNode *node=new ListNode(p->val);
				ptr1->next=node;
				ptr1=node;
			}	
		// 记录最后offset个节点
			else
			{
				ListNode *node=new ListNode(p->val);
				ptr2->next=node;
				ptr2=node;
			}
			p=p->next;
		}
		// 拼合两个链表，拼合front->next的原因是front已经被初始化，front->val不是原链表中的数字
		ptr2->next=front->next;
		// 返回back->next的原因是back已经被初始化，back->val不是原链表中的数字
		return back->next;
    }
};
```