### 解题思路
此处撰写解题思路
蛮有意思的一道题。跟追及问题很像。高赞的解释很清楚了，我再用符号表达一遍。
设非环长度为$a$，环的长度为$b$，快慢指针从head出发，快指针每次走两步，慢指针每次走一步。
 第一次快慢指针相遇时 慢指针走的步数为$s_1$,快指针走的步数为$f_1$，
则满足公式$f_1=s_1+nb$(总步数相等)和$f_1=2s_1$（步数的2倍关系）很显然可以得到$s1=nb$。现在问题是相遇的地点可能在环中心，需要走$t$步可以到达目标位置$s_2$环的边缘。$s_2=s_1+t=nb+a$，（由$s_2$的位置决定）因此$t=a$,即慢指针需要走a步到达指定位置。而恰好，我们可以用一个指针从head走$a$步和慢指针在指定位置相遇
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null||head.next==null)
            return null;
        ListNode slow=head;
        ListNode fast=head;
        
       while(true){
           if(fast==null||fast.next==null)
               return null;
           fast=fast.next.next;
           slow=slow.next;
           if(fast==slow)
               break;
       }
        fast=head;
        while(fast!=slow){fast=fast.next;
                         slow=slow.next;}
        return fast;
        
        
        
    }
}
```