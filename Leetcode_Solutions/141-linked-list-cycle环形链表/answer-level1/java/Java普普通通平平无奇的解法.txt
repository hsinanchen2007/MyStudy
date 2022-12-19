### 解题思路
**循环删除节点！
利用链表带环的特性判断！**
示例：
1. **不带环的情况**
head = [3,2,0,-4], pos = -1
*依次删除某节点的下一节点，然后指向下一节点如下：*
head = [0,-4]（删除了节点3后的节点2，并指向节点0）
最终p.val = 0, p.next.next = null
（当链表长度为奇数时，终止条件为p.next = null）
2. **带环的情况**（如下图：）
![微信图片_20200408174955.jpg](https://pic.leetcode-cn.com/5bbfeb8a4d9c86485084a40bb08bad4e343fa7b56dd933c22d670e02e1f1a1d5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200408174955.jpg)
head = [3,2,0,-4], pos = 1（链表中有一个环，节点-4指向节点2）
*依次删除某节点的下一节点，然后指向下一节点如下：*
删除了节点3后的节点2，并指向节点0:
head = [0,-4,2,0,-4,2,0,-4,...]
删除了节点0后的节点-4，并指向节点2:
head = [2,0,2,0,2,0,...] 
删除了节点2后面的节点0
head = [2,2,2,...] 
最终节点2的下一个节点为它自己




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
        if (head == null || head.next == null){
            return false;
        }
        while (head != head.next){
            if (head.next == null || head.next.next ==null){
                return false;
            }
            head.next = head.next.next;
            head = head.next;
        }
        return true;
    }
}
```