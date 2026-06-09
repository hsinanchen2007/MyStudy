### 解题思路

![image.png](https://pic.leetcode-cn.com/04e751c243a65ba8169abfbc7b7c8229960a32f4f0df3ab7e85abe7158381296-image.png)
看注释壁咚。
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans_head = new ListNode();

        ListNode nowNode = ans_head;
        int jinwei = 0;
        
        //结构上面: 如何遍历链表。
        while(l1!=null || l2!=null || jinwei == 1){
            
            ListNode nextNode = new ListNode();
            
            int a = 0;
            int b = 0;

            if(l1 != null)  {
                a = l1.val;
                l1 = l1.next;
            }
            if(l2 != null) 
            {
                b = l2.val;
                l2 = l2.next;
            } 

            //考虑 是否进位。
            if(a + b + jinwei > 9)  {  //注意： 上次进位也要考虑到本次中。
                nextNode.val = a + b + jinwei - 10 ;
                jinwei  = 1;
            }
            else {
                nextNode.val = a + b + jinwei ;
                jinwei = 0;
            }
            
            nowNode.next = nextNode;
            nowNode = nextNode;

        }
        return ans_head.next;
    }
}
```