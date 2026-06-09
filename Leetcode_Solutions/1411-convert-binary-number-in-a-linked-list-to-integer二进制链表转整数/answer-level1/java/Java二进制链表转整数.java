### 解题思路
1、首先计算二进制链表的长度n（结点的总个数）
2、运用Math.pow(double a,double b)方法，算2^n-1相加即转成整数
时间复杂度O(n)
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
    public int getDecimalValue(ListNode head) {
        ListNode cur = head;
        int n = 0,sum = 0;
        while(cur != null){
            n++;
            cur = cur.next;
        }
        cur = head;
        while(cur != null){
            if(cur.val != 0){
                sum += Math.pow(2,n-1);
            }
            n--;
            cur = cur.next;
        }
        return sum;
    }
}
```