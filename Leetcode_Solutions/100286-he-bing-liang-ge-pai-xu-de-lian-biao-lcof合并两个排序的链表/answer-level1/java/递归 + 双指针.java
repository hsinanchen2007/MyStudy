### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //递归解法
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null){
            return null;
        }
        if(l1 == null && l2 != null){
            return l2;
        }
        if(l1 != null && l2 == null){
            return l1;
        }
        if(l1.val <= l2.val){
            ListNode node = mergeTwoLists(l1.next, l2);
            l1.next = node;
            return l1;
        }else{
            ListNode node = mergeTwoLists(l1, l2.next);
            l2.next = node;
            return l2;
        }
    }
}
```

```java
class Solution {
    //双指针解法
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node = new ListNode(0);
        ListNode ans = node;
        while(l1 != null && l2 != null){
            if(l1.val <= l2.val){
                node.next = l1;
                l1 = l1.next;
            }else{
                node.next = l2;              
                l2 = l2.next;
            }
            node = node.next;
        }
        while(l1 != null){
            node.next = l1;
            l1 = l1.next;
            node = node.next;
        }
        while(l2 != null){
            node.next = l2;
            l2 = l2.next;
            node = node.next;
        }
        return ans.next;
    }
}
```