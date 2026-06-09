### 解题思路
递归解法，递归的思路是:1.明确当前递归函数的定义
2.找到数据规模更小的问题
3.假设更小规模的问题已经解决 推导大问题如何解决
4.确定递归终止条件

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
    //递归解决方案 1>2>3>4>5>6>7   
    //2>1>4>3>6>5>7
    //确定方法定义:k个一组反转链表 返回的是新的head节点
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode cur = head;
        for(int i =0;i<k;i++){
            if(cur == null) {
                return head; //表示节点数目不够k个 直接返回
            }
            cur = cur.next;
        }
        ListNode kNext = cur;
        
       ListNode newHead = reverseN(head,kNext);
       ListNode tmp = reverseKGroup(kNext,k);
       head.next = tmp;
        return newHead;
    }
    
    // 1->2>3>4   3>2>1>4
    public ListNode reverseN(ListNode head,ListNode kNext){
        if(head.next == kNext){
            return head;
        }
        ListNode newHead = reverseN(head.next,kNext);
        head.next.next = head;
        head.next = kNext;
        return newHead;
    }
}
```