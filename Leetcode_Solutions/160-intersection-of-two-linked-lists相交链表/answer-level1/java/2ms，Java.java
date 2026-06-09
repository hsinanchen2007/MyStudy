思路：
1.设置ab双指针，ij分别表示两个链表的“长度”；
2.使a、b分别指向两链表的尾部，并判断是否相等，是则相交，不是则返回null；
3.此时将a指向长度更长的链表，i为更大值；
4.利用长度差值使两链表“长度”相同，再逐一取值进行判断。

```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        ListNode a = headA, b = headB;
		int i = 0 , j = 0;
		while (a.next != null || b.next != null) 
        {
			if(a.next != null)
			{
				i++;
				a = a.next;
			}
			if(b.next != null) 
            {
				j++;
				b = b.next;
			}
		}
		if(a != b)
			return null;
        a = headA;
        b = headB;
		if(j > i) 
		{
			a = headB;
			b = headA;
			j ^= i;
			i ^= j;
			j ^= i;
		}
		int y = 0 ;
		while( y++ < i - j )
			a = a.next;
		while(true) {
			if(a == b)
				return a;
			a = a.next;
			b = b.next;
		}
    }
}
```
