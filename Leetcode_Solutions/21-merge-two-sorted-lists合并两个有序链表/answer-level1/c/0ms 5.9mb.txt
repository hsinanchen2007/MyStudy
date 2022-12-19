### 解题思路
基本思路：
		l1: 0->2->3
		l2: 1->3->5
		将l2的数据插入l1中合适的位置

### 代码

```c
/* 
	基本思路：
		l1: 0->2->3
		l2: 1->3->5
		将l2的数据插入l1中合适的位置

	如以上情况:第一次数据比较：0 < 1:则l1往后走一步;
		第二次数据比较: 这时候l1的数据是2了，l2的数据还是1，2 > 1 ,所以将l2所指的数据插入l1所指位置的前一个，所以需要保存前一个数据的地址last，l2往后走一步；
		第三次数据比较：l1:2 < l2:3 所以如第一次比较一样，l1往后走一步；
		第四次数据比较：l1:3 = l2:3 如第二次比较；
		第五次数据比较: l1:3 < l2:5 如第一次一样，l1往后走一步，此时l1走完了，则需要通过循环将l2剩余部分插入l1中；
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	struct ListNode *last, *mid, *rs;    //last指针保存要插入节点的前一个位置，mid指针用于向l1中插入数据时临时指针，rs用于保存结果的头指针。

	if (!l1)
		return l2;
	else if (!l2)
		return l1;

	if (l1->val > l2->val)	//将l1链表作为第一个数据比较小的那个，后序将符合条件的l2的数据插入l1；
	{
		mid = l1;
		l1 = l2;
		l2 = mid;
	}
	rs = l1;	//用rs指针保存头结点；
	if (l1->val == l2->val)    //第一个数据值相同时，将l2第一个数据插入l1中，l1，l2均往后移动一个单位，主要是为了初始化last指针；
	{
		mid = l2;
		l2 = l2->next;
		mid->next = l1->next;
		l1->next = mid;
		last = mid;
		l1 = mid->next;
	}

	while(l1 && l2){
		if (l1->val >= l2->val)
		{
			mid = l2;
			l2 = l2->next;
			mid->next = l1;
			last->next = mid;
			last = mid;
		}else{
			last = l1;
			l1 = l1->next;
		}
	}

	while(l2){
		mid = l2;
		l2 = l2->next;
		mid->next = NULL;
		last->next = mid;
		last = mid;
	}

	return rs;

}
```