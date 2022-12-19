# 方法1：递归
小的移动，最后返回最大的

```java
class Solution {
   public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       if (l1==null)return l2;
       if (l2==null)return l1;
       if (l1.val>l2.val){
           l2.next=mergeTwoLists(l1,l2.next);
           return l2;
       }else {
           l1.next=mergeTwoLists(l1.next,l2);
           return l1;
       }
   }
}
```
**复杂度分析：**


# 方法2：迭代
创建头节点，指向1，2中最小的，移动最小的指针，12在进行比较，按照这个过程进行迭代，直到1 or 2指向null
最后还剩下一个节点没有指向，最后在进行一次判断l1是null最后的节点就是l2。或者反之

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode pre=new ListNode(0);
        ListNode head=pre;
        while (l1!=null&&l2!=null){
            if (l1.val>l2.val){
                pre.next=l2;
                l2=l2.next;
            }else {
                pre.next=l1;
                l1=l1.next;
            }
            pre=pre.next;
        }
        pre.next=l1==null?l2:l1;
        return head.next;
    }
}
```
**复杂度分析：**
    时间复杂度O（n）
    空间复杂度O（1）



