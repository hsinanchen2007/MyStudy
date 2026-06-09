```
public class ListNode {
     public var val: Int
     public var next: ListNode?
     public init(_ val: Int) {
         self.val = val
         self.next = nil
     }
 }


class MyLinkedList {

    var head: ListNode?
    
    init() {
        head = nil;
    }
    
    func get(_ index: Int) -> Int {
        if index < 0 || head == nil {
            return -1
        }
        
        if index == 0 {
            return head!.val
        }
        
        var curIndex = 0;
        var curNode = head
        while curIndex < index && curNode?.next != nil {
            curNode = curNode?.next
            curIndex += 1
            if curIndex == index {
                break;
            }
        }
        
        if (curIndex == index) {
            return curNode!.val
        }else{
            return -1
        }
        
    }
    
    func addAtHead(_ val: Int) {
        if head == nil {
            head = ListNode(val)
        }else{
            let newHeadNode = ListNode(val)
            newHeadNode.next = head;
            head = newHeadNode;
        }
    }
    
    func addAtTail(_ val: Int) {
        if head == nil {
            head = ListNode(val)
        }else{
            var cur = head;
            while cur?.next != nil {
                cur = cur?.next
            }
            cur?.next = ListNode(val)
        }
    }
    
    func addAtIndex(_ index: Int, _ val: Int) {
        if index < 0 {
            addAtHead(val)
            return
        }
        
        if head == nil {
            if index > 0 {
                return
            }else{
                head = ListNode(val)
                return
            }
        }
        
        var curIndex = 0
        var curNode = head
        var lastNode: ListNode?
        
        while curIndex < index && curNode?.next != nil {
            lastNode = curNode
            curNode = curNode?.next
            curIndex += 1
        }
        
        if curIndex == index {
            if index == 0 { // 在头节点插入
                curNode = ListNode(val)
                curNode?.next = head
                head = curNode
            }else{ // 在其他位置插入
                lastNode?.next = ListNode(val)
                lastNode?.next?.next = curNode
            }
        }
        else if (curIndex == index - 1) {
            curNode?.next = ListNode(val)
        }
    }
    
    func deleteAtIndex(_ index: Int) {
        if index < 0 || head == nil {
            return
        }
        
        var curIndex = 0
        var curNode = head
        var last:ListNode? = nil
        
        while curIndex < index && curNode?.next != nil {
            last = curNode
            curNode = curNode?.next
            curIndex += 1
            
            if curIndex == index {
                break
            }
        }
        
        if curIndex == index {
            if curIndex == 0 {
                head = head?.next
            }else{
                last?.next = curNode?.next;
                curNode?.next = nil;
            }
        }
    }
}

```