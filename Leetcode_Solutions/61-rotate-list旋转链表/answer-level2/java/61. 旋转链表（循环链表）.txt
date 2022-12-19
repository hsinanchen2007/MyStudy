### 解题思路
首尾指针相连形成单循环链表，向右移动K个位置，即在n-n%k断掉链表，新链表的头指针指向的是原地址是n-n%k+1
之前没考虑会超出的情况，被[0,1,2],4失败了好几次
![image.png](https://pic.leetcode-cn.com/b98acb8c7ba6cf961af06bd20c9c2a4ebd0c5eec4c7d2666a13d03cdfa5a666e-image.png)

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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||head.next==null||k==0)return head;
        ListNode q = head;
        int n = 1;
        while(q.next!=null){
            q = q.next;
            n++;
        }
        k = k%n;
        if(k==0)return head;

        q.next = head;
        for(int i = 0;i<n-k;i++){
            q = q.next;
        }
        ListNode p = q.next;
        q.next = null;
        return p;
    }
}
```