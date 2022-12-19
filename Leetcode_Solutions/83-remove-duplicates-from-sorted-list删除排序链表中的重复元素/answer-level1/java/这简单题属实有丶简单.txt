### 解题思路
![QQ截图20200121154119.png](https://pic.leetcode-cn.com/a36662f505ccec2363f47de2236d1571164eef74071fc6ae65a27edf34d1d22b-QQ%E6%88%AA%E5%9B%BE20200121154119.png)

我起了，一枪秒了，有什么好说的
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
         if(head==null){
            return null;
        }
        ListNode res=head;
        ListNode p=head;
        ListNode next=p.next;
        while(next!=null){
            if(next.val==p.val){
                p.next=next.next;
                next=p.next;
            }else{
                p=p.next;
                if(p==null) return res;
                else next=p.next;
            }
        }
        return res;
        
    }
}
```