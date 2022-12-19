定义奇偶节点指针even和odd，
起始odd指向为head,even指向head.next
每一次交换操作后，当前odd和even两个节点的next节点就是下一次要进行操作的两个节点位置
所以两个指针前进一个单位，就可以迭代操作了，逻辑稍稍有点复杂，但代码思路很清晰
```
class Solution {
    public ListNode oddEvenList(ListNode node) {
        if(node == null || node.next == null || node.next.next == null) return node;
        ListNode even = node.next;//定义偶节点
        ListNode  odd = node;//定义奇节点
        while(even!=null &&even.next!=null){
           ListNode next = even.next;//定义偶节点的下一个奇节点用于交换节点
           even.next = next.next;
           next.next = odd.next;
           odd.next = next;
           //一次交换完成，此时，偶节点的下一个节点必定是下一个偶节点
            odd = odd.next;
            //奇节点移一位让下一个奇节点接在上一个奇节点后
            even = even.next;
            //偶节点移位到下一个偶节点
        }
            return node;


    }
}
```

