大循环通过cur指针步进；
same标记当前是否正处在重复元素；

找到不相等的元素时触发条件，这时分两种情况：
① 当不处于重复元素时，pre标志位向前移动；
② 当处于重复元素时，pre的next指针跳过当前项，相当于删除所有重复元素
```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode mhead = new ListNode(Integer.MIN_VALUE);
        mhead.next = head;
        ListNode cur = mhead;
        ListNode pre = mhead;
        boolean same = false;
        while(null != cur){
            if(cur.next == null || cur.next.val != cur.val){
                if(same){
                    pre.next = cur.next;
                    same = false;
                } else {
                    pre = cur;
                }
            } else {
                same = true;
            }
            cur = cur.next;
        }
        return mhead.next;
    }
}
```
