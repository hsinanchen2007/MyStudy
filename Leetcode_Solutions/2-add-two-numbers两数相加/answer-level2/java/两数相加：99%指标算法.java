### 解题思路
- 耗时击败 99.97%
- 内存消耗击败 95.89%

这道题难在处理进位上，需要额外判断相加结果是否为两位数，不仅需要保留个位上的数字，同时要考虑进位问题，让下一个结点在下一次得到相加结果时额外加1，同时要注意999991+9这样的连续进位的情况。所以我们大致是这样设计的：
1. 考虑到是链表结构，所以直接上遍历，两链表值相加后，同时让两个链表的指针向后移动
2. 有可能两个链表的长度不统一，出现长度不统一时，就需要进行额外的判断，如果某个链表的指针已经走到null，就跳过
3. 有可能出现进位情况，甚至连续进位，我们需要将进位后的处理，设计到完成相加后的位置来保证不被上一次的进位影响。
直接上代码：

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
        ListNode result = new ListNode(0), p = result;  //初始化头结点
        while (l1 != null || l2 != null){   //任意一个链表没有完成遍历时，继续遍历
            if(p.next == null) p.next = new ListNode(0);  //若没有下一个结点，创建接收运算结果的下一个结点
            p = p.next;   //移动指针到待操作结点
            if(l1 != null){     //若第一条链表遍历还未结束，加上该结点存储的值，并将指针后移
                p.val+=l1.val;   //直接加上结点值
                l1 = l1.next;    //向后移动指针
            }
            if(l2 != null){   //同上，第二条链表的遍历
                p.val+=l2.val;
                l2 = l2.next;
            }
            if(p.val >= 10) {   //如果大于等于10表示需要进位
                p.val%=10;    //留下个位的数值
                p.next = new ListNode(1);  //为下一个结点提前准备好初始值为1的结点
            }
        }

        return result.next;  //注意：需要返回头结点的下一个结点
    }
}
```