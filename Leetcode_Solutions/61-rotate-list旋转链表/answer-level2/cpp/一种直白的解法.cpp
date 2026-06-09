1、思路：

        我们首先把单链表转换成循环单链表，顺便记录下链表元素的个数，然后根据k值来计算我们需要在哪个位置设置为头结点，哪个地方的next指针指向NULL；

2、寻找旋转后链表的头和尾：

●我们将循环链表写成一个圈的的形式，那么我们就能想到链表旋转了多少次，就等效于NULL沿着相反的方向移动了多少次。由于题目所给的链表结构中没有前驱指针，因此，我们又重新思考如何实施我们的想法。

●由于题给链表结构含有后继指针，因此想办法转换为从前面向后遍历得到头尾位置。因此用总长度减去 k 便可得到头指针需要移动多少个结点。其上一个便是尾节点

3、计算断开位置：

●我们首先考虑 k 小于链表长度的情况：这种情况下，我们计算方法在2中已经叙述，就是用链表长度减去 k 

●再考虑 k 大于链表长度的情况：这种情况下，我们最好把 k 减小到比链表长度小。最直接的办法就是直接循环， k 每次都减一个链表长度，直到bi链表长度小。
还有一个方法就是用 k 除以链表长度即可算出超出几个链表长度。详细计算方法如下（假设链表长度为count）：
                                        ((k / count) + 1)*count - k
我们再减去1，得到尾结点的位置

详细代码如下：
```
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return NULL;
		ListNode *tmp = head;
		int count = 0;
		while (tmp->next)
		{
			tmp = tmp->next;
			count++;
		}
		count++;
		tmp->next = head;
		tmp = tmp->next;
		int tail = ((k / count) + 1)*count - k - 1;
		while (tail > 0)
		{
			tmp = tmp->next;
			tail--;
		}
		head = tmp->next;
		tmp->next = NULL;
		return head;
	}
};
```
