### 解题思路
1:首先解决链表完全翻转，使用pre,start,next来记录链表相邻三个节点的位置，然后将指针反转，注意处理第一头结点的情况pre初始化为NULL
2：解决链表K组翻转，与完全翻转类似，将每一组视为一个单链表完全翻转问题，需要处理的额外情况就是需要将前一段与后一段连接，同时考虑好边界问题
在这里pre start next作用与1中相同，nextS记录下一段的起始位置，每一段的pre初始化为下一段的最后一个元素，因为下一段翻转后最后一个元素就是第一个元素，这样正好可以衔接前后两段，若最后一段不足K，则不需要翻转，那么pre就初始化为下一段的开头nextS.
3.在这里使用for循环找到正确指针的位置来遍历链表，也可以通过计算链表的长度，除以K来确定循环的次数遍历链表
4.节点完全复用原来的节点，只有几个指针变量等空间占用，O(1)
  时间复杂度O(n)
### 代码

```c
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	struct ListNode *pre = NULL;
	struct ListNode *start = NULL;
	struct ListNode *end = NULL;
	struct ListNode *nextS = head; //下一段指针
	struct ListNode *next = NULL; //当前指针下一结点
	struct ListNode *ret = NULL;
	if (k == 1) return head;
	int s = 0; //当前段序号
	while (nextS) {
		start =end= nextS;
		for (int i = 0; i < k-1; i++) {
			end = end->next;
			if (!end&&s==0) return  head;
			else if (!end) return ret;
		}
		if (s == 0) ret = end;
		pre = nextS = end->next;
		if (nextS != NULL) {
			for (int i = 0; i < k - 1; i++) {
				pre = pre->next;
				if (!pre) {
					pre = nextS;
					break;
				}
			}
		}
		while (start != nextS) {
			next = start->next;
			start->next = pre;
			pre = start;
			start = next;
		}
		s++;
	}
	return ret;
}

```