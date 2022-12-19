### 解题思路
核心思路：
    1. 修改链表ListNode l1,每次将l1.val = l1.val + l2.val + 进位，无需再new 第三个链表,节约空间复杂度
    2. 声明一个l3的链表，引用指向l1,然后不断修改l3的值,l1也就会随之改变，最后返回l1即可

读代码：
1、如果l1 不等于null,l2等于null,则直接返回 l1
    如果l2 不等于null,l1等于null，则直接返回l2
2、将l1 赋值给l3，然后循环l3
3、每次循环 l3.val = l2.val+ l3.val + 十进位（其实此时修改的是l1.val），同时 l2 = l2.next , l3 = l3.next
4、如果 l2 != null（l2的链表长度比l3（l1）的长度要长） 且 l3 ==null，则需要扩展l3的next节点
    如果 b（进位数） > 0 ，表示需要进位，则执行同样操作 扩展l3.next 节点
5、循环结束，直接返回l1即可
    

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
        if (l1 != null && l2 == null) {
            return l1;
        }
        if (l2 != null && l1 == null) {
            return l2;
        }
        ListNode l3 = l1;
        int b = 0;
        while (l3 != null) {
            l3.val += b;
            l3.val += l2 == null ? 0 : l2.val;
            b = l3.val / 10;
            l3.val = l3.val % 10;

            l2 = l2 != null ? l2.next : null;
            if (l2 != null || b > 0) {
                if (l3.next == null) {
                    l3.next = new ListNode(0);
                }
            } else {
                break;
            }
            l3 = l3.next;
        }
        return l1;
    }
}
```