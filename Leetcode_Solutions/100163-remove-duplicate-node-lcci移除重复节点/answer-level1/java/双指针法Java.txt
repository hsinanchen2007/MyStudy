### 解题思路
![image.png](https://pic.leetcode-cn.com/aae0e87ca6b24fdd80453cbca01281c3d7d3d3263b7708420f47a11261ac9e08-image.png)

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
    public ListNode removeDuplicateNodes(ListNode head) {
         if (head != null) {
            //pre指针指向节点1，cur指针指向节点1，set集合添加第一个节点的值；
            ListNode cur = head;
            ListNode pre = cur;
            Set<Integer> set = new HashSet<>();
            set.add(head.val);
            //pre指针指向节点1，cur指针指向节点2，开始遍历
            cur = cur.next;
            while (cur != null) {
                if (!set.contains(cur.val)) {
                    //如果set集合不含有cur指针指向的节点的值，1)向set集合添加该值;2)pre指向cur指针指向的节点；3）cur指针往后移1位
                    set.add(cur.val);
                    pre = cur;
                    cur = cur.next;
                } else {
                    ///如果set集合含有cur指针指向的节点的值，将该节点从链表中移除，1)cur指针往后移1位；2）pre的next指针指向cur
                    cur = cur.next;
                    pre.next = cur;
                }
            }
        }
        return head;
    }
}
```