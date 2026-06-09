### 解题思路
此处撰写解题思 
使用递归合并两个链表，所需时间较大，慎用。

### 代码

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int len = lists.length;
        if (len == 0) {
            return null;
        }    
        // 将n个链表以中间为对称，合并，即合并 len = 3
        while(len>1) {
            for (int i=0; i<len/2; i++) {
               //1.list[0] = merge(list[0],list[2])
               //2.list[0] = merge(list[0],list[1])              
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            len = (len+1)/2;//len=2
        }
        return lists[0];
    }
    
    // 合并两个链表
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       if(l1 == null) return l2;
       if(l2 == null) return l1;
       ListNode merNode = null;
       if(l1.val < l2.val){
           merNode = l1;
           merNode.next = mergeTwoLists(l1.next,l2);

       }else{
           merNode = l2;
           merNode.next = mergeTwoLists(l1,l2.next);
       }
       return merNode;
    }
}
```