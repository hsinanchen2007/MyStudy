### 解题思路
应该是迭代法，用了五六个指针，没有用其他存储结构，原地反转，空间复杂度O(1),时间复杂度O(n)
感觉好罪恶啊，调试的时候用了IDE的debug模式写的，哭唧唧

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null){
            return null;
        }
        //最终的头结点
        ListNode h = null;
        ListNode start = head;
        ListNode end = null;

        ListNode pre = null;
        ListNode cur = head;
        ListNode next = head.next;

        while(cur != null && canDo(cur, k)){
            int n = k;
            while(cur != null && n > 0){
                cur.next = pre;
                pre = cur;
                cur = next;
                //如果当前遍历到null，则不需要继续了
                if (cur != null){
                    next = cur.next;
                }
                n --;
            }
            //设置头节点
            if (h == null){
                h = pre;
            }
            //将前后两个链表串起来
            if (end != null){
                end.next = pre;
            }
            pre = null;
            end = start;
            start = cur;
        }

        //将剩余的不符合k的进行追加
        if (cur != null){
            end.next = cur;
        }

        return h;
    }

    //判断当前链表开始 大于 k个节点
    private boolean canDo(ListNode head, int k){
        int n = k;
        while(head != null){
            if(n > 0){
                n--;
            }else{
                return true;
            }
            head = head.next;
        }
        return head == null && n == 0 ;
    }
}
```