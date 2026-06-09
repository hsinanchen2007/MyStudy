对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 ![插入过程](https://pic.leetcode-cn.com/76d630e3778307474f4994cdca49aee8e9dfc4342fd843f66d3ba5e189c72c49-file_1581060012549)

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

    输入: 4->2->1->3
    输出: 1->2->3->4
示例 2：

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list


### 解题思路
#### 硬写
设定一个最小的头节点h，来避免边界条件的处理，以及方面插入过程
申请一个cur代表遍历当前节点以及pcur代表当前节点的前驱节点。
1. 如果cur 大于等于 pcur的值，说明cur局部有序，不用修改
2. 如果cur 小于pcur，则通过pcur指向cur.next来删除cur。
3. 然后根据h节点从头节点向后遍历找到第一个大于cur节点值的节点，并将cur插入到此节点。
4. 重复上述步骤


##### Python
```python
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        h = ListNode(-9999999999999) # 定义头节点的前驱节点
        h.next = head
        pcur = h
        cur = h.next 
        while cur: ## 开始遍历每个节点
            if pcur.val <= cur.val: #正常有序
                pcur = pcur.next 
                cur = pcur.next
                continue
            pcur.next = cur.next #删除此节点
            cur.next = None
            pre = h 
            while pre.next and pre.next.val <= cur.val:
                pre = pre.next
            cur.next = pre.next  # 拼接
            pre.next = cur
            cur = pcur.next # 继续下个把遍历
        return h.next
```

##### Java
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
    public ListNode insertionSortList(ListNode head) {
        ListNode h = new ListNode(-2147483648); // 定义头节点的前驱节点
        h.next = head;
        ListNode pcur = h;
        ListNode cur = h.next; 
        while(cur != null){
            if(pcur.val <= cur.val){
                pcur = pcur.next;
                cur = pcur.next;
                continue;
            }            
            pcur.next = cur.next;  // 删除此节点
            ListNode pre = h ;
            while(pre.next != null && pre.next.val <= cur.val)
                pre = pre.next;
            cur.next = pre.next;  // 拼接
            pre.next = cur;
            cur = pcur.next; // 继续下个把遍历
        } // 开始遍历每个节点
        return h.next  ;
    }
}
```



#### 大佬解法
这似乎不是插入排序呀。

```java
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode lo = head, hi = head, mid = head;
        while(hi.next != null && hi.next.next != null)
        {
            mid = mid.next;
            hi = hi.next.next;
        }
        hi = mid.next;
        mid.next = null;
        ListNode i = insertionSortList(lo);
        ListNode j = insertionSortList(hi);
        ListNode n_head = new ListNode(-1);
        ListNode k = n_head;
        while(i != null || j != null)
        {
            if(i == null)
            {
                k.next = j;
                break;
            }
            else if(j == null)
            {
                k.next = i;
                break;
            }
            else if(i.val < j.val)
            {
                k.next = i;
                k = k.next;
                i = i.next;
            }
            else
            {
                k.next = j;
                k = k.next;
                j = j.next;
            }
        }
        return n_head.next;
    }
}
```