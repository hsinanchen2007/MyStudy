先把那个反转链表1做一下, 那个题目搞懂了, 这个就很容易懂了
分三步走:

1. 遍历到m的前一个位置 `superior ` (因为需要遍历到前一个位置, 所以最好创建一个虚拟头结点)
2. 定义一个节点使其指向m的位置 `cur = superior.next`
然后就是按照反转链表1的方式直接套就好了. 需要注意一下循环的边界
循环结束之后, 脑海中要浮现出三个指针的位置(浮现个屁, 用纸笔画一下吧骚年)
 `prev 指向n-m的位置,也就是最后一个旋转的节点`
`cur和next都指向n-m的下一个位置` 
3.  最后调整一下`superior.next(m处的节点)和prev(n-m位置处)`这两个节点的指向即可


还是搞张图吧, 网上找的
![RGIF2.gif](https://pic.leetcode-cn.com/508a840d01087f4136666001ec9180c238834f6caefdb6d2b2e4063d785bffd8-RGIF2.gif)


```cs
class Solution {
     public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode superior = dummyHead;

        // 1. 遍历至m的前一个节点
        for ( int i = 1; i < m; i ++ ) {
            superior = superior.next;
        }

        ListNode prev = null;
        ListNode cur = superior.next;

        // 2. 180°旋转爆炸
        for ( int i = 0; i <= n-m; i ++ ) {
            ListNode next = cur.next;

            cur.next = prev;
            prev = cur;
            cur = next;
        }
        
         // 3. 修改m和n-m位置处的节点的指向
        superior.next.next = cur;
        superior.next = prev;
        return dummyHead.next;
    }
}
```
