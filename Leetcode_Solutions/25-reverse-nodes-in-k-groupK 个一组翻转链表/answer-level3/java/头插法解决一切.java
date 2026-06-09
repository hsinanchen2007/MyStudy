### 解题思路
头插法，每次更新逻辑头节点，并且用 flag 节点表示是否还剩 k 个节点，满足就反转，不满足就说明反转完毕。

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
        if(head == null || k < 2) return head;

        // 创建哑巴节点
        ListNode help = new ListNode(-1);
        help.next = head;

        // flag 用于判断是否剩余链表长度 > k
        ListNode flag = help;

        // 头插法的逻辑头节点，每次都在需要反转的 k 组的前一个节点，
        // 最初需要反转的是第一个所以其前节点为 help
        ListNode logicHelper = help;

        // flag 每次会向后找 k 个 如果没找到则为空
        while(flag != null){

            // flag 往后找 k 个
            for(int i = 0; i < k; i++){
                flag = flag.next;
                if(flag == null) break;
            }

            // 如果存在 k 个节点 反转 k 个链表
            if(flag != null){
                ListNode p = logicHelper.next;
                ListNode q = logicHelper.next.next;

                for(int i = 0; i < k - 1; i++){
                    p.next = q.next;
                    q.next = logicHelper.next;
                    logicHelper.next = q;
                    q = p.next;
                }

                // 获得当前的逻辑哑巴节点, 因为节点顺序已变，还原 flag
                logicHelper = p;
                flag = logicHelper;
            }    
        }

        return help.next;
    }
}
```