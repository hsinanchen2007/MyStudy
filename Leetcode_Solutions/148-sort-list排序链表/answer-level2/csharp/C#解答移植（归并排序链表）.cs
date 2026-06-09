# 归并排序
其实还有点没看懂代码，总之先移植C#上成功运行了。
```
public ListNode SortList(ListNode head)//归并排序
{
    ListNode dummyHead = new ListNode(0);
    dummyHead.next = head;
    var p = head;
    int length = 0;
    while (p != null)
    {
        ++length;
        p = p.next;
    }

    for (int size = 1; size < length; size <<= 1)
    {
        var cur = dummyHead.next;
        var tail = dummyHead;

        while (cur != null)
        {
            var left = cur;
            var right = cut(left, size); 
            cur = cut(right, size); 

            tail.next = MergeTwoLists(left, right);
            while (tail.next != null)
            {
                tail = tail.next;
            }
        }
    }
    return dummyHead.next;
}

public ListNode cut(ListNode head, int n)
{
    var p = head;
    while (--n != 0 && p != null)
    {
        p = p.next;
    }

    if (p == null) return null;

    var next = p.next;
    p.next = null;
    return next;
}
public ListNode MergeTwoLists(ListNode l1, ListNode l2)//合并两个有序链表
{
    var listHead = new ListNode(0);
    ListNode curr = listHead;
    int x, y;
    while (l1 != null || l2 != null)
    {
        x = (l1 != null) ? l1.val : int.MaxValue;
        y = (l2 != null) ? l2.val : int.MaxValue;
        if (x < y)
        {
            curr.next = new ListNode(x);
            if (l1 != null) l1 = l1.next;
        }
        else
        {
            curr.next = new ListNode(y);
            if (l2 != null) l2 = l2.next;
        }
        curr = curr.next;
    }
    return listHead.next;
}
```
![image.png](https://pic.leetcode-cn.com/7ca45e87ff3b2f2578b941729eecce330617755a3b651bb21e0733f0dfd0d5a6-image.png)

