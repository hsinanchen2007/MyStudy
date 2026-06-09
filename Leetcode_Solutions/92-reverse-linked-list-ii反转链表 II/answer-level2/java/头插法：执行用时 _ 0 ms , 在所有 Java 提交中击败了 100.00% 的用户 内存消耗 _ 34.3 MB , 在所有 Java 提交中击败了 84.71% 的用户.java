### 解题思路
首先创建一个头结点，防止在m为1时将头结点弄丢了
用快慢指针分别找到第 m - 1 和 第n + 1个结点
对中间的进行反转
头插法：顾名思义每次插入一个数据将其设为头结点，即能完成逆序的工作
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n){
            return head;
        }
        ListNode start = new ListNode(-1);  //创建一个新的头结点
        start.next = head;
        int firstcount = 0;
        int secondcount = 0;
        ListNode first = start;
        ListNode second = start;
        while(firstcount < n + 1){  //找到第 n + 1个结点
            if(secondcount < m - 1){    //找到第 m - 1个结点
                second = second.next;
                secondcount++;
            }
            first = first.next;
            firstcount++;
        }
        second.next = reverse(second.next, n - m + 1, first);   //对 m--n 共n - m + 1个结点用头插法逆序并将开头初始为第n + 1个结点
        return start.next;
    }
    public ListNode reverse(ListNode head, int k, ListNode midHead){
        ListNode q = head;
        ListNode result = midHead;  //将开头初始第n + 1个结点
        int count = 0;
        while(count != k){  //从第m 开始每次都将新的结点插入到开头共 n - m + 1项
            ListNode p = q;
            q = q.next;
            p.next = result;
            result = p;
            count++;
        }
        return result;
    }
}
```