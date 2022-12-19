**分析：**
1. 首先判断链表是否为空，为空则直接返回
2. 循环链表中的所有节点，如果当前节点的val等于val时，则表示需要删除该节点，需要将当前节点的上一节点的next指向当前节点的下一个节点；这样就需要记录当前节点的上一个节点由于单向链表所以新建一个listNode,将listNode.next = head
3. 定义两个指针 temp 和 temp2；temp=listNode，temp2=listNode.next(其实指向的是head)
4. 循环链表 判断temp2.val 是否等于val 如果等于则将temp.next指向temp2.next；这样在temp2中就将当前节点删除
5. 如果 temp2.val不等于val，则temp2 = temp2.next;temp=temp.next；继续下个几点进行比较
6. 终止条件是 temp2 == null时；


```
public ListNode removeElements(ListNode head, int val) {
		if(head == null){
			return head;
		}
		ListNode listNode = new ListNode(-1);
		listNode.next = head;
		ListNode temp = listNode;
		ListNode temp2 = temp.next;
		for (;;){
			if (temp2.val == val) {
				temp.next = temp2.next;
				temp2 = temp2.next;
			}else{
				temp2 = temp2.next;
				temp = temp.next;
			}
			if(temp2 == null){
				break;
			}
		}
		return listNode.next;
	}
```
