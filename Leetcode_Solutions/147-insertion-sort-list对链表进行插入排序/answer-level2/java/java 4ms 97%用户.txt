### 解题思路
![图片.png](https://pic.leetcode-cn.com/1192807581a91387c01db43b2b75149ceda86ab106546345145e59a49edc2deb-%E5%9B%BE%E7%89%87.png)

就是对插入排序的模拟，
与数组不一样，这里只有后指针，就是说找位置要从前往后找。
找到后，因为链表天生插入优势，所以不用像数组一样移动元素，只需要移动指针。
这里有一点需要注意的：
**1、node = null 不能删除node，只能通过node.next = null 断链**
这里有两个小技巧：
**1、创建最小头节点**
**2、判断当前是否是最大值，最大就不用插入了，加速排序**
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
    public ListNode insertionSortList(ListNode head) {
        if(head == null) return null;
        ListNode current = new ListNode(Integer.MIN_VALUE);
        current.next = head;
        ListNode newHead = current;
        int max = current.next.val;
        while (current.next != null){
            ListNode valNode = current.next;
            if (valNode.val < max) {
                for (ListNode p = newHead; p != current; p = p.next){
                    if (p.val <= valNode.val && p.next.val > valNode.val){
                        if (p.next != current.next) insert(p, current);
                        break;
                    }
                }
            }else{
                max = valNode.val;
                current = current.next;
            }
        }
        return newHead.next;
    }
    private void insert(ListNode node1, ListNode node2){
        ListNode valNode = node2.next;
        ListNode node = new ListNode(valNode.val);
        node.next = node1.next;
        node1.next = node;
        node2.next = node2.next.next;
    }
}
```