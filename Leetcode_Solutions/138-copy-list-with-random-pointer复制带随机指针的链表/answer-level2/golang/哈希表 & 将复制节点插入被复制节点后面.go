### 解题思路1

0ms(100%),3.4MB(100%)

使用哈希表，使用哈希表查询复制节点的Next和Random域
  
需要特别注意的就是当链表只有一个节点时，其Next和Random可能指向其本身，因此复制所得的节点需要进行相应的指向

### 代码

```golang
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    if head == nil {
        return nil
    } else if head.Next == nil {
        node := &Node{
            Val: head.Val,
        }
        if head.Next == head {
            node.Next = node
        }
        if head.Random == head {
            node.Random = node
        }

        return node
    }
    nodesMap := make(map[*Node]*Node)
    cur := head
    for cur != nil {
        nodesMap[cur] = &Node{
            Val: cur.Val,
        }
        cur = cur.Next
    }
    cur = head
    for cur != nil {
        node, _ := nodesMap[cur]
        node.Next = nodesMap[cur.Next]
        node.Random = nodesMap[cur.Random]
        cur = cur.Next
    }

    return nodesMap[head]
}
```

### 解题思路2

0ms(100%),3.3MB(100%)

将复制节点插入被复制节点后方，遍历两轮：第一轮调整复制指针的随机指针，第二轮从链表中抽离出来，组成新的复制链表

### 代码

```go
func copyRandomList(head *Node) *Node {
    if head == nil {
        return nil
    } else if head.Next == nil {
        node := &Node{
            Val: head.Val,
        }
        if head.Next == head {
            node.Next = node
        }
        if head.Random == head {
            node.Random = node
        }

        return node
    }
    // 将复制节点插入被复制节点后面
    node := head
    for node != nil {
        newNode := &Node{Val: node.Val}
        next := node.Next
        newNode.Next = next
        node.Next = newNode
        node = next
    }
    // 调整复制节点的随机指针
    node = head
    for node != nil {
        newNode := node.Next
        if node.Random != nil {
            newNode.Random = node.Random.Next
        }
        node = newNode.Next
        
    }
    // 从链表中抽离出复制节点
    var newHead, newTail *Node
    node = head
    for node != nil {
        newNode := node.Next
        node.Next = newNode.Next
        node = newNode.Next
        newNode.Next = nil
        if newHead == nil {
            newHead = newNode
            newTail = newNode
        } else {
            newTail.Next = newNode
            newTail = newNode
        }
    }

    return newHead
}
```