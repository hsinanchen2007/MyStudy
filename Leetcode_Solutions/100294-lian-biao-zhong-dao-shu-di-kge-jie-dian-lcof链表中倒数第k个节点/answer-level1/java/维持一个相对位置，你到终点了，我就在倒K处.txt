### 解题思路
用两个指针，一个在原链表的头，另一个在他后面k个结点处。两个节点一起往后移动一步，可以维持原来区间大小不变。一旦快指针指向null，慢指针就恰好指在倒数第k个结点处。

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode fastHead = head;
        ListNode newHead = head;
        while(k > 0){
            //fastHead在newHead前面K个节点存储，他俩的相对位置作为循环不变量
            fastHead =  fastHead.next;
            k--;
        }
        //当fastHead指向null时，newHead正好是倒数第k个结点。
        while(fastHead != null){
            fastHead = fastHead.next;
            newHead = newHead.next;
        }
        return newHead;
    }
}
```