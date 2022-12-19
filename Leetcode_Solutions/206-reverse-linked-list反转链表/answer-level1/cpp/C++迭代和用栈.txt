### 解题思路
用栈其实思路很简单，因为栈先进后出的性质，我们只要把链表按顺序入栈，再出栈，就很自然可以得到一个逆置的链表。
迭代的思路其实就是看官方题解的，代码补上了注释供大家参考。

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
ListNode* reverseList(ListNode* head) 
{
    //这里是用栈实现
	stack<ListNode*> helpStack;  //用栈来实现
	helpStack.push(NULL);  //栈中放入一个NULL作为栈底元素
	while (head != NULL)  //链表元素入栈
	{
		helpStack.push(head);
		head = head->next;
	}  
	head = helpStack.top();  //首节点
	helpStack.pop();
	ListNode* ptr{ head };
	while (!helpStack.empty())  //栈不空就出栈
	{
		ptr->next = helpStack.top();
		ptr = ptr->next;
		helpStack.pop();
	}
	return head;
    
	//这里是迭代实现
    ListNode* pre{ NULL };  //前一个节点
	ListNode* curr{ head };  //当前节点

	while (curr != NULL)  //当前节点不为空
	{
		ListNode* nextTemp{ curr->next };  //保存当前节点的下一个节点
		curr->next = pre;  //将当前节点的下一个节点修改为前一个节点
		pre = curr;  //保存修改后的前一个节点
		curr = nextTemp;  //指针移动到后一个节点
	}

	return pre;
}
};
```