- 解题思路不在赘述，也是hash表和双指针。
- A-B，B-A拼接后两个遍历的长度相同，若有相交，在尾部会重合。
- **考虑边界条件，若两个链表无重合，则在遍历过程中获取到A和B的尾节点时即可判断出来**。
- 写完两个方法测试通过之后习惯点开题解，发现在使用双指针解题中很少有人考虑链表不重合情况，无短路时可能导致的无限循环问题！
- 因此去除尾节点判断，提交，竟然通过了！
- 随便修改测试用例为无重合链表。测试超时！
- 照此推断，**此处的测试用例应该是没有设置无重合链表情况？**
- 测试用例如下：欢迎测试
 ```
0
[0,9,1,2,4]
[3,4,2]
0
0
```
```java []
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       if (headA==null ||headB==null ) return null ;
        ListNode CursorA=headA;
        ListNode CursorB=headB;
      ListNode endA=null;
        ListNode endB=null;
        while (CursorA!=CursorB){
            if (endA!=null&endB!=null&&endA!=endB){
                return null;
            }
            if (CursorA.next==null){
                endA=CursorA;
                CursorA=headB;

            }else{
                CursorA=CursorA.next;
            }
            if (CursorB.next ==null) {
                endB=CursorB;
                CursorB=headA;

            }else {
                CursorB=CursorB.next;
            }
        }
        return CursorA;
    }
```
