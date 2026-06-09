### 解题思路
![image.png](https://pic.leetcode-cn.com/b86c58ff26698bc473e9e2f48968eb10988174719716163a576af5b8523beb33-image.png)

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
    public ListNode oddEvenList(ListNode head) {
      if(head==null||head.next==null){
			return head;
		}
		ListNode odd=head;
		ListNode even=head.next;
		while(even!=null&&even.next!=null){
			ListNode temp=even.next;
            //保持奇数位置节点的下一个始终指导偶数位置节点的头部
			ListNode temp2=odd.next;
            //交换节点顺序
			odd.next=even.next;
			even.next=temp.next;
			odd.next.next=temp2;
            //奇偶节点各自后移
			odd=odd.next;
			even=even.next;
		}
		return head;

    }
}
```