```
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        while(curr != null){
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev==head; 
    }
}
```
各位大佬，谁能告诉我这样先翻转再比较为啥有错
![image.png](https://pic.leetcode-cn.com/9d8232e4f7fe063f1b90cfa4d1d5592d8062a36002cfa20bc4d362e09dbb374b-image.png)
