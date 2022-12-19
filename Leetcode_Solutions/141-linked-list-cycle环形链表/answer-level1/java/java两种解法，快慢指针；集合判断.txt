题目中的pos是辅助题目判断是否是环的。我们不需要去理会
**方法一：快慢指针**
```
   /*
     * 方法一：快慢指针法，快指针每次前进两格，满指针每次前进一格。
     * 如果快慢指针相遇，则有环。如果快指针=null则无环
     * */
    public boolean hasCycle(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        while (fast!=null||fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if (slow==fast){
                return true;
            }
        }
        return false;
    }
```
**方法二：利用额外的空间判断**
```
    /*
    *方法二，利用额外的空间，存储遍历过的结点，同时添加进额外空间。当next结点已经存在，则有环。
    *因为需要添加和判断是否存在。所以额外空间采用hashset
    * */
    public boolean hasCycle(ListNode head) {
        Set<ListNode> set=new HashSet<>();
        ListNode curr=head;
        while (curr!=null){
            if (set.contains(curr)){
                return true;
            }
            set.add(curr);
            curr=curr.next;
        }
        return false;
    }
```