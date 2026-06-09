思路就是双指针，都从头结点出发，第一个指针先走k步，使得两个节点之间一直保持k，然后两个指针一起走直到前指针到头，这时再返回val就可以了
```
class Solution {
    public int kthToLast(ListNode head, int k) {
        ListNode former = head, latter = head;
        for(int i = 0;i < k;i++)
        former = former.next;
        while(former!=null){
            former = former.next;
            latter = latter.next;
        }
        return latter.val;
    }
}
```
