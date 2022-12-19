执行用时 :1 ms, 在所有 Java 提交中击败了99.83%的用户
内存消耗 :42.6 MB, 在所有 Java 提交中击败了7.75%的用户

### 解题思路
1.第一次全链遍历：求的链的总长度
2.第二次遍历：把前半段链表逆序，拆成两个链表，第一个链是逆序的，第二个链是后半段正序的
3.一一对比元素的val值

### 代码

```java
class Solution {
    public boolean isPalindrome(ListNode head) {

        ListNode p = head;
        int i = 0;
        int num = 0;

        if(head == null || head.next == null){
            return true;
        }

        while(p != null){
            p = p.next;
            i++;
        }

        num = i/2;


        ListNode c = head;
        ListNode pi = null;

        ListNode l1 = null;
        ListNode l2 = null;

        int n = 0;
        while(c != null){
            ListNode t = c.next;
            c.next = pi;
            pi = c;
            c = t;
            n++;
            if(n == num){
                if((i%2) == 0){
                    l2 = c;
                }else{
                    l2 = c.next;
                }
                break;
            }
        }

        l1 = pi;

        while(l1!=null){
            if(l1.val != l2.val){
                return false;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        
        return true;

    }
}
```