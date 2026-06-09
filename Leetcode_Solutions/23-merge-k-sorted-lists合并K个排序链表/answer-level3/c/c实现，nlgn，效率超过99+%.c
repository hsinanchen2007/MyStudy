
如果对快速排序或者归并排序有了解的同学代码也许一眼就能看明白，有点参考他们的思想
程序主题思想还是递归，归并或者快速排序的思想复杂度为nlgn级别，
因为是递归，如果嵌套十分深入的话，还是需要一点堆栈的空间的

mergeTwoLists 这个函数可以不看，是之前做题已经实现的程序，。直接拿来用就可以了
核心代码不过 _mergeKLists(...) 函数里面的十行有余
如果有bug,请指正
```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode  *p, *q;

	if (!l1) {
		return l2;
	}

	if (!l2) {
		return l1;
	}

	/* 建立新的头结点 指向L1 */
	head.next = l1;
	l1 = &head;
 
	/* 遍历l2节点 */
	while (l2) {
		p = l1->next;
		q = l2->next;

		if (!l1->next) {
			l1->next = l2;
			break;
		}
  
		if (p->val >= l2->val) {
			l1->next = l2;
			l2->next = p;
			l2 = q;
		}

		l1 = l1->next;
	}
	return head.next;
}

struct ListNode* _mergeKLists(struct ListNode** lists, int listsSize)
{
	int count;
	struct ListNode* l1, *l2;
	count = listsSize;

	if (count == 0) {
		return NULL;
	} else if (count == 1) {
		return lists[0];
	} else if (count == 2) {
		return mergeTwoLists(lists[0], lists[1]);
	}
 
	l1 = _mergeKLists(&lists[0], (count+1)/2);
	l2 = _mergeKLists(&lists[(count+1)/2], count - (count+1)/2);
  
	return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{  
	return _mergeKLists(lists, listsSize);
}
```
