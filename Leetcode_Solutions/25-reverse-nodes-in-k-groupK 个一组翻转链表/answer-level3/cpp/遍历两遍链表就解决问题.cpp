不用太多的辅助空间，只需要几个指针变量和整形变量就可以解决问题，只需要遍历两次链表。时间复杂度不大，应该是线性复杂度，因为只需要遍历两遍链表外加一些节点赋值操作。其实思想稍微简单，就是先求出链表的节点的总数，然后求出需要翻转的组数，组数=链表节点总数/k，然后依次翻转每一组的节点，然后再把每一组依次连接起来。这样就完成了整个链表的组数的翻转。

```
ListNode* reverseKGroup(ListNode* head, int k) 
{

	if (head == 0||k==0||k==1)
	{
		return head;
	}

	ListNode * t = head;
	int sum = 0;
	while (t)
	{
		sum++;
		t = t->next;
	}
	int node_num = sum / k;  //需要翻转的组数
	int curr_num = 0;   //当前翻转的组数

	ListNode * node = head;
	ListNode * first = head;
	ListNode * after = head->next;
	ListNode * sub_node = head;

	int reverse_num = 0;
	int move_node = 0;
	while (curr_num < node_num)
	{
		//翻转节点
		auto tt = after->next;
		sub_node->next = after->next;
		after->next = head;
		head = after;
		reverse_num++;
		after = tt;


		if (reverse_num % (k-1) == 0)   //达到翻转一组的数量的时候  开始翻转下一组   并且连接以翻转的组
		{
			curr_num++;
			if (++move_node % 2 == 0)  //第一次需要翻转两组之后再连接两组，后面只需要翻转一组就连接一组
			{
				move_node = 1;
				auto t = node->next;

				node->next = head;
				node = t;
			}

			if (curr_num == 1)   //第一次特殊 
			{
				first = head;
			}
			if (after == nullptr)    //判断是否刚好整数倍翻转  是则after可能为空  判断
			{
				return first;
			}
			head = after;
			after = after->next;
			sub_node = head;
			
		}
	}
	return first;
}
```

写的比较乱，也没整理就直接提交了，其他办法没尝试，看到题目就这样操作了。
