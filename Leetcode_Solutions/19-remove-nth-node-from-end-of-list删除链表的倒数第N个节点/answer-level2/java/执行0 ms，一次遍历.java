### 解题思路
变量名含义看下面的注解
比如链表 1 2 3 4 5，寻找倒数第二个数
第一次len=1,n=2,len<n,removenode=1
第二次len=2,n=2,len<n,removenode=1
第三次len=3,n=2,len>n,removenode=2,pernode=1
第四次len=4,n=2,len>n,removenode=3,pernode=2
第五次len=5,n=2,len>n,removenode=4,pernode=3
下一个节点为空，说明链表到头了，直接移除removenode节点即可
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
        if (head.next == null)
            return null;//如果链表只有一个，倒数第1应该就是它本身啊，不明白为什么正确答案是空，只好写个这个判断了
        int len = 0;
        ListNode pernode = head;//定义移除节点的前一个节点
        ListNode removenode = head;//定义一个移除节点，初始化为第一个节点
        ListNode newhead = head;
        while (newhead != null) {
            len++;//如果不为空，链表长度加1
            if (len > n) {//如果链表长度超过了n，说明移除节点要开始
                pernode = removenode;
                removenode = removenode.next;
            }
            if (newhead.next == null) {
                if (len == n) {//如果长度=n，说明要移除的是第一个节点
                    head = removenode.next;
                } else {
                    pernode.next = removenode.next;
                    removenode.next = null;
                }
            }
            newhead = newhead.next;
        }
        return head;
    }
}
```