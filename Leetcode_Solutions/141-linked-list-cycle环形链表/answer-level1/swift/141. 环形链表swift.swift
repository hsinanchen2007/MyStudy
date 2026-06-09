```
public class ListNode {
  public var val: Int
  public var next: ListNode?
  public init(_ val: Int) {
      self.val = val
      self.next = nil
  }
}

func haveCicleOfListNode(list: ListNode?) -> Bool {

    var p1 = list
    var p2 = list
    while p2 != nil {
        let n1 = p1?.next
        let n2 = p2?.next?.next
        if n1?.val == n2?.val {
            return true
        } else {
            p1 = n1
            p2 = n2
        }
    }
    return false;
}
```
