通过观察，其实不难发现一个index=n的中间结点为n/2+1.(这里不做推论,分开奇偶两种场景应该会很好理解)

则index=n+1的中间结点为(n+1)/2+1.这里我们分两种场景讨论.

- n为偶数

n/2+1=(n+1)/2+1.==>n+1的中间结点和n的中间结点是相等的

- n为奇数

n/2+1+1=(n+1)/2+1.==>n+1的中间结点为n的中间结点的下一个结点

则我们最终可以得到这个程序
```java
public class MiddleLink {
    //Definition for singly-linked list.
    public static class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
    }
    static class Solution {
        public ListNode middleNode(ListNode head) {
            ListNode middle=head;
            int index=1;
            ListNode current=head;
            while(current.next!=null){
                current=current.next;
                index++;
                if (index==2) {
                    middle=current;
                }else if (index%2==0) {
                    middle=middle.next;
                }
            }
            return middle;
        }
    }
}
```