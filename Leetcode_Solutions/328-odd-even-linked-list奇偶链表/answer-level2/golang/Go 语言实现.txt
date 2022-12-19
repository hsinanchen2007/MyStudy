```go
/* 思路：
用两个指针，oddLastNode 指向最后一个奇数节点，evenLastNode 指向最后一个偶数节点
从偶数节点开始处理，将它后面的奇数节点移掉，插入到 oddLastNode 的后面
注意 evenLastNode.Next = head 避免出现环
*/

func oddEvenList(head *ListNode) *ListNode {
    // 指向最后一个奇数
    oddLastNode := head
    newList := head
    if head != nil {
        head = head.Next
    }
    
    // 从第二个节点开始操作
    for head != nil {
        if head.Next == nil {
            return newList
        }
        // evenLastNode 指向最后一个偶数
        evenLastNode := head
        
        // 把后面的奇数节点拿出来
        if head.Next != nil {
            oddNode := head.Next
            
            if head.Next.Next != nil {
                head.Next = oddNode.Next
            }
            
            head = oddNode.Next
            evenLastNode.Next = head
            
            // 将这个偶数节点插入到 oddLastNode 后面
            next := oddLastNode.Next
            oddLastNode.Next = oddNode  
            oddLastNode = oddNode   
            oddLastNode.Next = next
            
        }
    }
    return newList
}

```
