### 解题思路
这题主要考察链表尾插法，解题思路和官方所给的第二种方法一样，只是用C++实现。具体逻辑我不再详述代码中有注释。

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

class LinkList  //建立一个链表类，在下面操作中可以使逻辑更清晰
{
public:
	LinkList()  //初始化
	{
		head = new ListNode(NULL);
		last = head;
	}
	ListNode* getHead() { return head; }
	void addLast(ListNode* p)  //向链表末尾添加节点（尾插法）
	{
		last->next = p;
		last = last->next;
	}
private:
	ListNode* head;  //头节点
	ListNode* last;  //尾指针
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
    LinkList l3;  //创建一个链表
	while (true)
	{
		
		if (l1 == NULL)  //假如l1里的元素已经遍历完，此刻直接将l2里剩下的元素全部添加
		{
			l3.addLast(l2);  //将l2的当前节点加入l3尾部，此刻两个链表已经链接为一个链表
			break; //退出循环
		}
		if (l2 == NULL)  //l2里的元素已经遍历完，同理
		{
			l3.addLast(l1);  //同上面
			break;
		}
		//此刻l1和l2都不为空
		if (l1->val <= l2->val)  //假如l1的节点值大于l2的节点值，将该节点添加，然后l1后移
		{
			l3.addLast(l1);  //添加到l3末尾
			l1 = l1->next;  //后移
		}
		else  //和上面同理
		{
			l3.addLast(l2);
			l2 = l2->next;
		}
	}
    // 题目所给链表不带头节点，所以我们返回头节点后一个元素（首个节点）
	return l3.getHead()->next;
    }
};
```