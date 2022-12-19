
设定如下的双指针，node1和node2，每次让node1.next=node2.next
![image.png](https://pic.leetcode-cn.com/f7aa03966e162d74d75db94aed19208f777feb36e96b12ec4e34d64249cbcd8c-image.png)
![image.png](https://pic.leetcode-cn.com/6e7a0d1fb8961e2e004bc0d2a9e7a5af133305a84411e6d174d13d7178ac8e04-image.png)

另外还要处理奇数末尾要指向偶数头部的处理

![image.png](https://pic.leetcode-cn.com/05c247500aaa372ff53241841d1b124f73a8f5224c98812cc6e015513ac5f797-image.png)



```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; } 
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode node1 = head;
        if(head == null || node1.next == null) {
            return head;
        }

        ListNode evenHead = node1.next;
        boolean nowIsOdd = true;
        while(node1 != null) {
            ListNode node2 = node1.next;
            
            if(node2 == null) {
                if(nowIsOdd) {
                    node1.next = evenHead;
                }
            } else if(node2.next == null && nowIsOdd) {
                    node1.next = evenHead;
            }
            else {
                node1.next = node2.next;
            }
            
            node1 = node2;      
            nowIsOdd = !nowIsOdd;          
        }    
        return head;
    }
}
```
