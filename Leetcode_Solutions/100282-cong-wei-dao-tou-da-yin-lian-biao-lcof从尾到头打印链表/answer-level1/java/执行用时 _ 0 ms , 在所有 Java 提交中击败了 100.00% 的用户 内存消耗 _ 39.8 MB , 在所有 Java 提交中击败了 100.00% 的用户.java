# 最简单的想法可能是最有效的。。。
```
    public int[] reversePrint(ListNode head) {
		int listNodeSize = 0;
		ListNode listNode = head;
		while (listNode != null) {//第一次循环计算链表大小
			listNodeSize++;
			listNode = listNode.next;
		}
		int result[] = new int[listNodeSize];//上面获得的链表大小用来创建数组
		while (head != null) {//再次循环给数组赋值
			result[listNodeSize - 1] = head.val;
			listNodeSize--;
			head = head.next;
		}
		return result;
	}
```
