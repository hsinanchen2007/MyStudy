### 解题思路
我们只需要找出需要删除节点的上一个元素，直接把找到的元素的next节点，替换成需要删除元素节点的next即可。
主要思路：
1、创建一个虚拟头节点，方便我们查找判断
2、循环判断当前节点的next节点的val是否等于需要删除的节点
3、如果找到了，直接把当前找到的元素节点的next 赋值成当前节点的后两个元素即可（**因为当前节点的下一个next节点就是我们需要删除的元素，**）。

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
    public ListNode deleteNode(ListNode head, int val) {

        // 创建虚拟头节点
        ListNode newhead = new ListNode(-1);
        newhead.next = head;

        // 创建临时变量获取头节点
        ListNode item = newhead;

        // 标识ID是否已经存在
        boolean falg = false;

        while (true) {
            // 判断是否需要继续循环
            if (item.next == null) {
                break;
            }
            // 判断元素下一个节点是否等于删除数值
            if (item.next.val == val) {
                falg = true;
                break;
            }
            // 元素后移
            item = item.next;

        }
        // 判断是否找到删除元素
        if (falg) {
            // 因为我们找到下一个元素就是我们需要删除的元素
            // 直接把当前节点的next节点，赋值成需要删除元素的next节点
            item.next = item.next.next;
        } else {
            System.out.printf("删除当前元素找不到，ID为 = %d \n", val);
        }
        return newhead.next;
    }
}
```