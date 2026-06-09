```
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) { 
        if(head == null){
            return null;
        }
        Set<Integer> set = new HashSet<>();
        set.add(head.val);
        ListNode cur = head.next;
        ListNode pre = head;
        while(null != cur){
            if(set.add(cur.val)){
                // 节点后移一位    
                pre = cur;  
            }else{
                // 需要删除当前节点
                pre.next = cur.next;

            }
            cur = cur.next;
        }
        return head;

    }
}
```
