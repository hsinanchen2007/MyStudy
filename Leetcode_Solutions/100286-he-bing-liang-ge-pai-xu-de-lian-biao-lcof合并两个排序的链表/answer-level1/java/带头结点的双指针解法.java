## 25.合并两个排序的链表

### Information

* TIME: 2020/02/14
* LINK: [Click Here](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)
* TAG: `List`

### Description

> 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

### Example

```text
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

### My Answer

> 迭代：创建头节点
>
> 双指针，每次把指向元素较小的指针加入新链表
>
> 最终情况，至多有一个链表还未遍历完：判空并将非空的剩余链表连接到新链表后

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(-1);
        ListNode tmpHead = head;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                tmpHead.next = l1;
                l1 = l1.next;
            }else{
                tmpHead.next = l2;
                l2 = l2.next;
            }
            tmpHead = tmpHead.next;
        }
        tmpHead.next = l1 == null? l2 : l1;
        return head.next;
    }
}
```

### Extend & Reference

> 来源：力扣（LeetCode）
> 链接：https://leetcode-cn.com
> 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### More

> **更多题解，请访问我的GitHub仓库：[LeetCode 刷题日记](https://github.com/ZhuoZhuoCrayon/my-Nodes/blob/master/Daily/README_2020.md)**
>
> [无效的图片地址](https://raw.githubusercontent.com/ZhuoZhuoCrayon/my-Nodes/master/Daily/img/mynode.png)
>
> [**更多笔记**](https://github.com/ZhuoZhuoCrayon/my-Nodes)：**`Vue` `Java SSM 框架` `阿里云服务器` `JavaScript/HTML/CSS`   `数据库` ...**
>
> **我的GitHub主页 -> [ZhuoZhuoCrayon](https://github.com/ZhuoZhuoCrayon)**
>
> 共勉~

