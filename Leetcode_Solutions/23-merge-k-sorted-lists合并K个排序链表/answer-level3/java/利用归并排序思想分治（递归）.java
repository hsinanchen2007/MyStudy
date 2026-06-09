![Screen Shot 2020-01-25 at 00.23.20.png](https://pic.leetcode-cn.com/80892b4b09a5097dec7b3840ab3e9dd8cba3b073acffb69874ecf234ca0c561e-Screen%20Shot%202020-01-25%20at%2000.23.20.png)


### 解题思路
基本和归并排序一模一样 唯一区别排的是链表不是数 利用之前写好的合并2个排序链表来解决
base case: 一个链表 
otherwise: 选中点进行分治
### 复杂度分析
list平均长度为n   k个list,共规模kn  
mergeTwoLists 时间复杂度O(n) 空间O(1)
使用归并排序的递归树分析我们可以发现每一层和为kn 树高为logk （因为我们在对k分治）
所以时间复杂度为 O(knlogk) 
空间复杂度：相当于数递归树中有多少个节点 每个stack frame占常数级空间
高度为logk 一次分叉两个 第k层2^logk = k个 总共1+2+4+...k 等比数列
(1-2^logk) / (1-2) = (1-k)/(-1)= k-1
所以空间复杂度O(k)
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode dummyhead = new ListNode(-1);
        ListNode cur = dummyhead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                cur.next = l1;
                l1 = l1.next;//l1 remain
            } else {
                cur.next = l2;
                l2 = l2.next;//l2 remain
            }
            cur = cur.next;
        }
        cur.next = l1 == null ? l2 : l1;//一个l会先变成null 连向非null的节点
        return dummyhead.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        return helper(lists, 0, lists.length - 1);
    }
    private ListNode helper (ListNode[] lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode l1 = helper(lists, l, mid);
        ListNode l2 = helper(lists, mid + 1, r);
        return mergeTwoLists(l1, l2);
    }
}
```