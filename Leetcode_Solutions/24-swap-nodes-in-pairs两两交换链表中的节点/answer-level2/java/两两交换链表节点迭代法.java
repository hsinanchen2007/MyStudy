![WechatIMG7.jpeg](https://pic.leetcode-cn.com/6972028cdabd2e743c859e26a39bd53bbe15e56b38e6aefaf8a2a6214f37953b-WechatIMG7.jpeg)
```
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode pp = null;
        ListNode next = null;
        ListNode prev = head;
        ListNode cur = head;
        while(prev != null && prev.next != null){
            cur = prev.next;
            next = cur.next;
            cur.next = prev;
            prev.next = next;
            if(pp != null){
                pp.next = cur;
            }else{
                head = cur;
            }
            pp = prev;
            prev = next;
        }
        return head;
    }
}
```
