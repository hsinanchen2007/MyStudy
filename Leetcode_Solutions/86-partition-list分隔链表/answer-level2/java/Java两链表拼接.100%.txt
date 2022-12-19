![image.png](https://pic.leetcode-cn.com/ad935315e989d7ce218d71bea6e88ecca300e2318294e343579e49ba6fad0108-image.png)

### 解题思路
![微信图片_20200220211135.jpg](https://pic.leetcode-cn.com/d30d9910bcedf4b443b51debda2c585f48deeb8dffc6e067c01a8b6c1c2ec9e4-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200220211135.jpg)
注释就写在代码里，跟着走一遍。

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
    public ListNode partition(ListNode head, int x) {
        ListNode minLink = new ListNode(0);//记录小值链表的头
        ListNode minP = minLink;//对小表操作用的指针

        ListNode maxnLink = new ListNode(0);//记录大值链表的头
        ListNode maxP = maxnLink;//同理

        while(head!=null){
            if(head.val < x){//找到小的值

                minP.next = head;//放入minLink中，操作指针后移一位
                minP = head;

            }else{

                maxP.next = head;//放入maxLink中，操作指针后移一位
                maxP = head;

            }
            head = head.next;
        }
        //遍历完成后记得后一段链表的最后节点指向null;
        maxP.next = null;
        //两段拼接
        minP.next = maxnLink.next;

        return minLink.next; 
    }
}
```