### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp,zhong,end;
		LinkedList<ListNode> lian = new LinkedList();
		int index = 0;
		while(head!=null) {
			lian.add(head);
            head = head.next;
			index++;
		}
		lian.remove(index-n);
       zhong = new ListNode(-1);
       end = zhong;
		for(ListNode x:lian) {
            temp = new ListNode(x.val);
            zhong.next = temp;
            zhong = zhong.next;
		}
        return end.next;
    }
}
```本人新手 第一个想到的就是LinkedList的强大功能 学习JAVA的时候以为是面向运行的语言 来到力扣世界才发现编程要考虑得这么多 感谢平台和平台的大佬们 正在努力追赶你们的脚步！ 