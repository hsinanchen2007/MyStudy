思路：设置进位变量carryBit，初始化为0，逐步读取l1和l2的各个结点。

倘若出现201 + 6032这类结点个数不同的情况，则单独递增l2

倘若出现5 + 5这类结果出现进位，但是两个链表均遍历结束的情况，则两个链表不再递增，而是逐位carryBit，直至进位为0；
代码如下：

    class Solution {
    public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0, b = 0;
		int carryBit = 0;      //进位变量
		ListNode *result = new ListNode(0);    //增添头结点，方便操作
		ListNode *current = result;       //存储第一个结点

		while (l1 || l2 || carryBit)       //l1，l2均遍历完成并且无进位
		{
			if (l1)         //l1还有结点，则修改a的值用于相加
				a = l1->val;
			if (l2)        //l2还有结点，则修改b的值用于相加
				b = l2->val;
			int sum = a + b + carryBit;                //求和
			ListNode *tmp = new ListNode(sum % 10);        //个位数添加至链表
			result->next = tmp;
			result = result->next;
			carryBit = sum / 10;                          //求取进位值
			if(l1)                  //判断两个链表的情况
				l1 = l1->next;
			if(l2)
				l2 = l2->next;
		}
		return current->next;
	}
    };