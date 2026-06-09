### 解题思路
每k个节点为一个范围，进行翻转；
记录好这k个节点的头和尾
原始的头翻转后变成尾，所以需要将这个头的next指向下个范围
原始的尾翻转后变成头，需要返回给上一个范围链接

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
        //基本判断，为空或者翻转范围小于2则无需操作
        if(head==null || k<2){
            return head;
        }
        //保存起始指针和翻转范围
        ListNode headBak = head;
        int kk = k; 
        //判断是否够k个节点进行翻转，不够的无需翻转直接返回起始节点
        while(--kk>0){
            headBak = headBak.next;
            if(headBak==null){
                return head;
            }
        }
        //进行一个范围的节点翻转，获取到下个范围的起始节点
        ListNode nextNode = swapNode(head,head.next,k);
        //进行下个范围的翻转，并将原始的头指向下个范围
        head.next = reverseKGroup(nextNode,k);
        //返回该范围的原始最后节点，作为上一个范围的后续节点
        return headBak;
    }

    public ListNode swapNode(ListNode node1,ListNode node2,int k){
        if(--k < 1 || node2==null){
            return node2; 
        }
        ListNode node = node2.next;
        node2.next = node1;
        return swapNode(node2,node,k);
    }
}
```