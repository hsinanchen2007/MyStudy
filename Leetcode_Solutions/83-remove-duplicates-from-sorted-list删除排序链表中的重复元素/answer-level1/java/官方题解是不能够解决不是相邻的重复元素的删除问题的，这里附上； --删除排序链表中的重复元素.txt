首先双指针是链表中不能够跨过的一种很巧妙的思路，这里用双指针实现：
    假设有两个指针，一个f，一个s；这两个指针开始都是head的引用，即：Node f = head;Node s = head;
    我要用一个指针作为其中一个节点的引用的同时让另外一个指针一直向下遍历比较val，如果val是相等的话那就直接跳过这个节点吧这个节点的前后连接在一起，所以就有了一种思路就是（s保持不动的前提下）
    if(f.next!=null&&f.next.val==s.val) {
				f.next = f.next.next;
			}else {
				f = f.next;
			}
那么当已经确定了当前s做引用的节点的node的后边已经没有跟此vul相等的vul了，就让s往后走一步（此时f已经到了最后边了)然后将f作为s的引用再次向后判断，直到最后这两个指针都到了最后的节点那么head也就被改造完毕了；所有代码附上：
```
public static Node removeRepeat(Node head) {
		if(head==null)return head;
		Node f = head;
		Node s = head;
		while(s.next!=null) {
			if(f.next==null) {
				if(s.next!=null) {
					f = s.next;s = s.next;
				}else {
					return head;
				}
			}
			if(f.next!=null&&f.next.val==s.val) {
				f.next = f.next.next;
			}else {
				f = f.next;
			}
		}
		return head;
	}
```

