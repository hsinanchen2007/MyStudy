看了好多大神们解法在原链表上弄，可能是自己智力不够，会绕晕了，我还是喜欢新建一个新链表来分析，反正新建一个链表也不占什么空间，理解起来会更容易一点。

1。插入排的思路就是把原链表分成两部分，一部分排好序的，一部分待排序
2。新建排好序的链表头   okHead  
3。将第一个节点加入到新链表中
4。遍历原链表从第二个节点开始
5。依次与新链表比较，找到第一个大于自己的，就插入到他前面。
6。找完了还没找到就插入到新链表尾部
7。遍历完结束
8。时间复杂度，最好情况是排好序的，只需要比较n-1次，  最坏情逆序的，需要比较n(n-1)/2次，杂乱无章情况下平均复杂度，O(n2)
算法稳定

 ListNode* insertionSortList(ListNode* head) {
	if (NULL == head)
	{
		return NULL;
	}
	ListNode* okHead = new ListNode(0);  //排好序的部分
	ListNode* tail = okHead;             //因为有可能会涉及到中间插入和尾插入，所以加个尾指针方便操作

    ListNode* cur = head->next;  //从原链表第二个开始循环，与新链表每个位置比较找到第一个比自己大的，就插入他前面，找不到就插入到链表最后
	
     //第一个节点加入到OKhead;     原链表分成okhead 和cur两个头组成，不断的比较
	okHead->next = head;
	ListNode* okcur = okHead->next;
    okcur->next = NULL;
	tail = okcur;

	ListNode* okpre = okHead;
	while (cur != NULL)
	{
		while (okcur != NULL)
		{
			if (cur->val < okcur->val) //在排好序的链表中，找到第一个比自己小的
			{
				ListNode* curNext = cur->next;
				cur->next = okpre->next;
				okpre->next = cur;
				cur = curNext;
				okcur = okHead->next; //处理完一个节点OK指针要还原
				okpre = okHead;
				break;
			}
			else if (okcur->next == NULL) //走到最后一个还是没找到，直接插到后面
			{
				ListNode* curNext = cur->next;
				tail->next = cur;
				cur->next = NULL;
				tail = cur;
				cur = curNext;

				okcur = okHead->next;///处理完一个节点OK指针要还原
				okpre = okHead;
				break;
			}
			okpre = okcur;
			okcur = okcur->next;
		}
	}
	return okHead->next;
}   