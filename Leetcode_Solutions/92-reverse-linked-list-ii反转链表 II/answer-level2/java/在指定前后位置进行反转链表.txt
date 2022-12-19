### 解题思路
关键就是保存开始反转节点的前一个节点，以及开始反转的节点。另外，从位置1时就开始反转需要注意，这时候没有反转节点的前一个节点

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
        ListNode curNode = head;
        ListNode preNode = null;//反转结束末尾节点
        ListNode pre = null;//记录开始反转节点的前面一个节点
        ListNode leftNode = null;//保存开始反转位置的节点
        int index = 1;
        while(curNode != null){
            if(index >= m && index <= n){//如果节点位置在m到n之间就反转
                if(index == m) leftNode = curNode;//保存开始反转位置的节点
                ListNode nextNode = curNode.next;
                curNode.next = preNode;//反转节点
                preNode = curNode;//节点后移
                curNode = nextNode;
                if(index == n){//反转结束，需要把链表前后断的位置连起来
                    if(pre != null) {//从大于等于2的位置开始反转
                        pre.next = preNode;//连接前面断的
                    }else{//从第一个位置开始反转
                        head = preNode;
                    }
                    leftNode.next = curNode;//连接后面断的
                    return head;
                } 
            }else{
                pre = curNode;//记录开始反转节点的前面一个节点
                curNode = curNode.next;
            }
            index++;
        }
        return head;
    }
}
```