### 解题思路：
- 我们通常做这种题的思路是设定两个指针分别指向两个链表头部，一起向前走直到其中一个到达末端，另一个与末端距离则是两链表的 `长度差`。再通过长链表指针先走的方式消除长度差，最终两链表即可同时走到相交点。
- **换个方式消除长度差：** 拼接两链表。
     设长-短链表为 `C`，短-长链表为 `D` （分别代表长链表在前和短链表在前的拼接链表），则当 `C` 走到长短链表交接处时，`D` 走在长链表中，且与长链表头距离为 `长度差`;
   
   以下图片帮助理解：当 `ha == hb` 时跳出，返回即可

![Picture1.png](https://pic.leetcode-cn.com/5651993ddb76ae6a42f0b338aec9382206f567041113f49d6ca670832ac75791-Picture1.png){:width=500}
{:align=center}

### 代码：
```Python []
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        ha, hb = headA, headB
        while ha != hb:
            ha = ha.next if ha else headB
            hb = hb.next if hb else headA
        return ha
```
```Java []
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ha = headA, hb = headB;
        while (ha != hb) {
            ha = ha != null ? ha.next : headB;
            hb = hb != null ? hb.next : headA;
        }
        return ha;
    }
}
```