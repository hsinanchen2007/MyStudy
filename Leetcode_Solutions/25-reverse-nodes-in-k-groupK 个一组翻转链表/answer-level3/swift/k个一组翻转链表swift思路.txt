#### 用入栈出栈的思路去解题,说说我的想法吧
- 因为一个swift的题解都没找到,所以就自己写了
- 代码效率不高,只击败了30%,我就奇了怪了,其他那么多swift通过的,就没有一个大神能共享点代码出来瞧瞧吗
- 总体思路就是搞个新的链 通过入栈出栈 然后把出栈的节点放进新的链,并设置好对应关系


```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        let new:ListNode = ListNode.init(0);
        var pointer = new;
        var f = head
        var kv = k
        
        var arr:[ListNode] = []
        
    
        while f != nil {
            
            kv = kv-1;
            arr.append(f!);
            if (kv == 0){
                //弹出arr中所有的节点
                let oringin = f!.next;
                var node1 = arr.last;
                pointer.next = node1;
                pointer = pointer.next!;
                arr.removeLast();
                let c = arr.count
                for lastnode in arr.reversed(){
                    
                    pointer.next = lastnode;
                    pointer = pointer.next!;
                    node1?.next = lastnode;
                    node1 = lastnode;
                    arr.removeLast();
                }
                node1?.next = oringin;
                //kv = k
                kv = k;
                f = oringin;
            }else{
                f = f?.next;
            }
            
        }
        for lastnode in arr{
            pointer.next = lastnode;
            pointer = pointer.next!;
            arr.removeLast();
        }
        return new.next;
    }
}
```