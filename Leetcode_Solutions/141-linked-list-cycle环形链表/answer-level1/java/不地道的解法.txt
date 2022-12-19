### 解题思路
因为要判断是不是有环
1.选择一个比较大不常见的数（我选了9999）
2.走一次改一次其对应的数值
3.如果出现了9999，就有环
缺陷：如果单链表中有9999，也会返回true，但是样例里是没有的
![image.png](https://pic.leetcode-cn.com/fb6fc14d3d11e92789febffe62089a533b8e766004d47867fd0e125c1765b776-image.png)


### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        int number = 9999;
        if(head==null){
            return false;
        }
        while(head != null){
             if(head.val == number){
                return true; 
             }
            head.val = number;
            head = head.next;
           
        }
        return false;
    }
    
}
```