蛤，随便看了一圈，好像没有按这个思路解题的：
先放手成绩
![image.png](https://pic.leetcode-cn.com/beef11013b13d64c6657266979c8760401c07a01ab0ee8a7f45bc3687167a243-image.png)

思路：遍历链表，每次经过一个节点时，把这个节点与下一个断开，并在这个节点后面连一个“特殊节点”

如果有环：那么一路遍历到链表最后，会因为有环而遍历到之前已经遍历过的一个节点，而这个节点在之前的操作中已经把下一个连接成了“特殊节点”，所以一路遍历下去时如果遇到这个“特殊节点”，则说明出现环，反而遍历到前面的某个节点了，返回true

如果没环：那么一路遍历到最后都不会跑回到前面已经遍历过的节点上，所以不会遇到“特殊节点”，那么到结尾null的时候停止并返回false即可

那么怎么设置这个“特殊节点”呢？这个节点的作用就是说明它连接的上一个节点已经被遍历过了，因此这个“特殊节点”必须足够特殊，以便跟链表里的其它节点区分开，所以我直接把头节点当成这个特殊节点（头节点是肯定不会在后面出现的，所以肯定可以区分开）。

感觉双指针法理论上会更快一些（两个两个跳），而我这个需要全部遍历完整个链表才能得出结果，但是个人感觉这样做很容易想到也易于理解，提交也是100%击败

放上代码：
```
class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;

        ListNode current = head;
        ListNode temp;

        while (current.next != null) {
            if (current.next == head) return true;

            temp = current.next;
            current.next = head;
            current = temp;
        }
        return false;
    }
}
```
