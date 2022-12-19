思路是：
新建一个虚拟头结点，记录去重后的队列。
每次比较时，先固定head，然后用一个指针check在新队列里从头到尾遍历比较，若没有和head重复的则将head加入新队列，若有重复则停止比较换下一个head。
唯一需要注意的细节就是，通过check的位置来判断此次比较是因为全部遍历完而结束的，还是因为中间有重复的而结束的。
最后当所有head都遍历完，返回dummy.next即可。
```
public ListNode removeDuplicateNodes(ListNode head) {
	ListNode dummy = new ListNode(-1);//新起一个头
	ListNode check = dummy;//游标指针，在新链表中遍历与head比较
	ListNode tmp;
	/*每次固定head，然后check从新头开始遍历，与head比较，重复则换下一个head，不重复则添加head*/
	while (head != null) {
		tmp = head.next;//先保存head.next
		check = dummy;//check归零位
		while (check.next != null && check.next.val != head.val) {
			/*如果重复，则停止比较,否则check向后继续*/
			check = check.next;
		}
		/*check.next == null表示新表比较完了，都没有重复的，可以将head加入
		 * check.next ！= null表示新表没遍历完，已经发现重复的了，head不能加入*/
		if (check.next == null) {
			check.next = head;
			head.next = null;
		}
		head = tmp;//head迭代
	}
	return dummy.next;
}
```
