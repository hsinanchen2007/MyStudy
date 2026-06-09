### 解题思路

详细参见 孙小美图解LeetCode82题 https://www.bilibili.com/video/av82352581/

一下是讲解的提纲: 

双指针法:
指针cur:从头到尾遍历,找到相邻值相同的Node(参考LeetCode83题)
指针pre:在cur前面用来进行删除(参考LeetCode203题)

需要虚拟头节点, 真正头节点head可能被删除,  需要返回dummy.next;
需要遍历到最后一个节点才能知道是否重复


重复与非重复情况的相同点:  cur 都需要向下移动, cur = cur.next;
 
重复与非重复情况的不同点:  没重复的时候, pre与cur距离两个Node, pre.next.next == cur;
有重复的时候, cur需要连续移动多次跨过相同值的Node

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode cur = head;
        ListNode pre = dummy;

        while(cur != null){
            while(cur.next != null && cur.val == cur.next.val){
                cur = cur.next;
            }
            cur = cur.next;

            if(pre.next.next == cur)     pre = pre.next;
            else                         pre.next = cur;
        }

        return dummy.next;
    }
}
```