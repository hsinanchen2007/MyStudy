解题思路如下分为一下几步。
1. 既然是已排序的那就先用个变量  lastvalue 来保存 最后一次节点的值
2. 遍历每个节点如果当前节点与下一个节点相等则保持更新  lastvalue 并移动指针到下一个节点。
3. 如果当前节点与下一个不相等，则与最后一次的值进行比较，如果相等则继续向下移动。
4. 以上条件都不满足则认为不是重复的节点。将节点设置到新的链表中。

代码如下：
```
if ( head == null ) return head;
			var current = head;
			var newhead = new SinglyLinkedListNode(0);
			var ptrnewhead = newhead;
			var lastvalue = (int?)null;
			while ( current != null ) {
				if ( current.next != null && current.val == current.next.val ) {
					lastvalue = current.val;
					current = current.next;
					continue;
				}
				if ( lastvalue == current.val ) {
					current = current.next;
					continue;
				}

				var temp = current.next;
				ptrnewhead.next = current;
				ptrnewhead = ptrnewhead.next;
				ptrnewhead.next = null;
				current = temp;

			}
			return newhead.next;
```
