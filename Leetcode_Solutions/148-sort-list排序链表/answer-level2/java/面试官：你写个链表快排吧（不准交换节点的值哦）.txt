1.快速排序（值交换）
快速排序的思想大家应该都知道，就是找一个pivot，把小于pivot分在一边，大于等于pivot的分在另外一边   
这个过程也叫做partition分区，数组的分区很好做，左右两个指针，不断交换就好了   
链表因为只能单向遍历，所以要换一种partition方法  
目的是使得左边的值都小于pivot，右边的值都不小于pivot
所以用一个索引记录左边的坐标，遍历过程中，每次碰到比pivot小的，都要交换一下，放到左边。
遍历完成后，再把pivot交换到中间来，这样就达成了目的。


``` java
class Solution {
    public ListNode sortList(ListNode head) {
        quickSort(head, null);
        return head;
    }
    
    void quickSort(ListNode head, ListNode tail){
        if(head == tail || head.next == tail) return;
        int pivot = head.val;
        ListNode left = head, cur = head.next;
        
        while(cur != tail){
            if(cur.val < pivot){
                left = left.next;
                swap(left, cur);
            }
            cur = cur.next;
        }
        swap(head, left);
        quickSort(head, left);
        quickSort(left.next, tail);
    }
```

2.快速排序（指针交换）
既然不然交换节点的值了，那怎么做分区操作呢？
相信大家都看过leetcode 86题，分隔链表

![截屏2020-04-0308.08.47.png](https://pic.leetcode-cn.com/4b15d7917649e3f2a917a8dd573369cc99d5504ed38b177e651d418f191b2c88-%E6%88%AA%E5%B1%8F2020-04-0308.08.47.png)


这道题的本质其实就是分区操作，简单借鉴一下，我们就可以写出如下代码：
```java
public class Solution {
    public ListNode sortList(ListNode head) {
        return quickSort(head);
    }

    ListNode quickSort(ListNode head){
        if(head == null || head.next == null) return head;
        
        int pivot = head.val;
        // 链表划分
        ListNode ls = new ListNode(-1), rs = new ListNode(-1);
        ListNode l = ls, r = rs, cur = head;
        
        while(cur != null){
            if(cur.val < pivot){
                l.next = cur;
                l = l.next;
            }else{
                r.next = cur;
                r = r.next;
            }
            cur = cur.next;
        }
        l.next = rs.next;
        r.next = null;
        
        // 递归调用,先重排右边的,再把指针置空,再重排左边的
        // 和归并排序很像的
        ListNode right = quickSort(head.next);
        head.next = null;
        ListNode left = quickSort(ls.next);
        
        // 拼接左半部分和右半部分
        cur = left;
        while(cur.next != null){
            cur = cur.next;
        }
        cur.next = right;
        return left;
        
    }
    
    
```
