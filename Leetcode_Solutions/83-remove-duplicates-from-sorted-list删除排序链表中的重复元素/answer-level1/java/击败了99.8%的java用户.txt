本题可以有递归和非递归两种解法，递归解法虽然效率差一点，但是能很好的练习如何写递归的思维。

```
public ListNode deleteDuplicates1(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode res = head;
        while (head != null && head.next != null) {
            //相等的话就删除下一个节点
            if (head.val == head.next.val) {
                head.next = head.next.next;
            } else {
                //不相等的话向前移动一位
                head = head.next;
            }
        }
        return res;
    }


    //递归写法
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        if (head.val == head.next.val) {
            //如果值和下一个值相同，删掉这个节点，即直接返回下一个节点
            return deleteDuplicates(head.next);
        } else {
            head.next = deleteDuplicates(head.next);
        }
        return head;

    }
```
