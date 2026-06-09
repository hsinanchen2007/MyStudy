思路：p，q两个指针，p指针指向结果集中最后一位，q用来遍历整个list。时间复杂度O(n)，空间复杂度O(1);

思路比较简单就直接放代码了

```
public ListNode deleteDuplicates(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		ListNode dumb = new ListNode(0); //新增一个节点是链表类题目的小技巧，防止出现结果为空的情况
		ListNode p = dumb, q = head;
		while (q != null) {
			int count = 1;
			while (q.next != null && q.next.val == q.val) {// 统计当前数值的个数
				q = q.next;
				count++;
			}
			if (count == 1) {//如果超过一个，则为重复，直接看下一个
				p.next = q;
				p = p.next;
				
			} 
			q = q.next;
		}
		//这里有个点需要注意一下，必须将p.next置为null，不然最后会有多余元素
		p.next = null;
		return dumb.next;
	}
```
