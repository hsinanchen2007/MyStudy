### 解题思路
正常思路，找到要插入的curr节点，将它拆出来，然后补到合适的位置。

【拆的部分】
  众所周知，要拆除一个节点，必须要知道它的前一个节点prev，即prev.next = prev.next.next
  我们可以利用这个prev节点，在不断拆除的while循环中，先将它与curr的值比较，
        如果prev值小于curr值，说明两者是顺序的，不需要拆除curr。
【补的部分】
   从头到尾遍历，找到合适的位置插入curr。
 


### 代码

```java

class Solution {
    public ListNode insertionSortList(ListNode head) {
      if (head == null || head.next == null){
            return head;
        }
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode prev = head;
        ListNode curr = null;
        ListNode findPosition = dummyHead;
        while (prev.next != null) {
            curr = prev.next;
            if (curr.val > prev.val){ // prev节点的值比curr小，说明两者是顺序的，直接进行下一轮
                prev = prev.next;     // 这里能够大幅度提速
            }else {
                prev.next = curr.next;         // 第一步，拆除curr节点
                curr.next = null;
                if (findPosition.val < curr.val){ // 可以省略这一步，似乎能快那么一丁点,?0.03ms?……
                    findPosition = dummyHead; 
                }
                while (findPosition.next != null && findPosition.next.val < curr.val) {
                    findPosition = findPosition.next; // 第二步：找到要插入的位置
                }
                curr.next = findPosition.next;  // 第三步：插入curr节点
                findPosition.next = curr;
            }

        }
        return dummyHead.next;
}
```