![Screen Shot 2020-03-31 at 10.09.22 PM.png](https://pic.leetcode-cn.com/579ee92cecccb30c03e86c86e6a6d810ddd7e8f549b17d51ec543b3d9c3db76d-Screen%20Shot%202020-03-31%20at%2010.09.22%20PM.png)

```
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null) return head;
        //先计算标记数组的大小，用链表val值去对应的数组索引值去记录
        //后面就简单了，删除重复链表节点即可
        int size=0;
        ListNode countNode = head;
        while(countNode != null){
            size = countNode.val > size ? countNode.val : size;
            countNode =countNode.next;
        } 
        boolean[] indexArray  = new boolean[size + 1];

        ListNode pre = new ListNode(-1);
        pre.next = head;
        ListNode cur = head;
        while(cur != null){
            if(indexArray[cur.val] == false){
                indexArray[cur.val] = true;
                cur = cur.next;
                pre = pre.next;
            }else{
                 pre.next = pre.next.next;
                 cur = pre.next;
            }
        }
        return head;
    }
}

```
