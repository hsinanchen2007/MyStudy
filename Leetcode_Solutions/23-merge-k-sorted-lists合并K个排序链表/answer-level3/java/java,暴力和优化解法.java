### 解题思路
  合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
  思路1, 暴力解法
  使用归并排序的思想, 对 merger(lists[i] list[i+1])
  总共merge k-1次,每次merge的时间复杂度是 lists[i] + lists[i+1],链表的长度
  所以总的时间复杂度是 (k - 1) * (lists[i] .len + lists[i+1].len))
  最终是  k * ( lists[0---> n] 长度和n, 是 kn
  时间复杂度是 O(1)
  思路2,
  对思路1进行优化,因为思路1中 lists[i[其实会进行两次对比
  其实我们可以使用归并排序思想,lists[i]进行一次对比 ,
   所以时间复杂度是 O(log2 k) * n (n 是所有链表元素的和)

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
     private static  final ListNode preHead = new ListNode(-1);
    private ListNode merge(ListNode h1, ListNode h2){
        if (null == h1)
            return h2;
        if (null == h2)
            return h1;
        // 使用一个头结点,方便处理,因为只申请一次,所以空间复杂度是 0(1)
        ListNode cur = preHead;
        while (h1 != null && h2 != null){
            if (h1.val < h2.val) {
                cur.next = h1;
                h1 = h1.next;
            }else {
                cur.next = h2;
                h2 = h2.next;
            }
            cur = cur.next;
        }
        if (h1 != null)
            cur.next = h1;
        if (h2 != null)
            cur.next = h2;
        return preHead.next;
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if (null == lists || lists.length == 0)
            return null;
        int step = 1;
        while (step < lists.length){
            for (int i = 0; i < lists.length - step; i+=step*2){
                lists[i] = merge(lists[i], lists[i + step]);
            }
            step = step * 2;
        }
        return lists[0];
    }
    public ListNode mergeRecusive(ListNode[] listNodes, int left, int right){
        if (left < right) {
            int mid = (left + right) / 2;
            mergeRecusive(listNodes, left, mid);
            mergeRecusive(listNodes, mid + 1, right);
            return  merge(listNodes[left], listNodes[mid + 1]);
        }
        return null;
    }
    public ListNode mergeKListsK_1(ListNode[] lists) {
        if (null == lists || lists.length == 0)
            return null;
        for (int i = 0; i < lists.length -1; i++){
            lists[i + 1] = merge(lists[i], lists[i + 1]);
        }
        return lists[lists.length - 1];
    }
}
```