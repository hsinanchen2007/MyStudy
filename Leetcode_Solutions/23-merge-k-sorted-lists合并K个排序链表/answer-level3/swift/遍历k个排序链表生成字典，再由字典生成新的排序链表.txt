思路：遍历k个排序链表，记录到字典中，字典的key是链表中的val，字典的value是k个链表中val出现的次数。然后通过字典再生成新的链表。算法的时间复杂度应该是O(nk),n是排序列表中元素的个数。
```Swift
func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
    var result: ListNode?
    var dict = [Int: Int]()
    var aNode: ListNode?
    
    for node in lists {
        aNode = node
        while aNode != nil {
            dict.updateValue((dict[aNode!.val] ?? 0) + 1, forKey: aNode!.val)
            aNode = aNode?.next
        }
    }
    
    for key in dict.keys.sorted() {
        for _ in 1...dict[key]! {
            if result == nil {
                result = ListNode(key)
                aNode = result
                continue
            }
            aNode?.next = ListNode(key)
            aNode = aNode?.next
        }
    }
    
    return result
}
```
