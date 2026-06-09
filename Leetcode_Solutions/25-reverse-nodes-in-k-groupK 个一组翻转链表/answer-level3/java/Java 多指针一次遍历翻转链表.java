
利用3个指针分别表示
上一段链表的结尾 pre
下一段待翻转的链表的开头 start 
和下一段带翻转的链表的结尾 end
每次end向后推进k次后判断end是否不为空，或者推进次数是否等于k
否则直接返回

然后记录end的next节点作为下一轮链表的开头。

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode start = dummy;
        ListNode end = dummy;
        while(end!=null){
            int oneTurn = k;
            while(oneTurn>0 && end!=null){
                end = end.next;
                oneTurn--;
            }
            if(oneTurn>0 || end == null) break;    

            ListNode next = end.next;
            end.next = null;
            start = start.next;

            /*
            可以内部写迭代反转，但是这样需要建立两个变量，上下容易冲突名字
            想的时候有点乱
            ListNode instart = start;
            ListNode inpre = null;
            while(instart!=null){
                ListNode innext = instart.next;
                instart.next = inpre;
                inpre = instart;
                instart = innext;
            }
            pre.next = inpre;
             */

            //直接新写一个函数会比较容易思考，减少混乱
            //下面这句话做的事情和上面注释里的一样。
            pre.next = reverse(start);

 
            start.next = next;
            end = start;
            pre = start;
        }

        return dummy.next;
    }

    public ListNode reverse(ListNode start){
        ListNode pre = null;
        while(start!=null){
            ListNode next = start.next;
            start.next = pre;
            pre = start;
            start = next;
        }
        return pre;
    }


}
```
